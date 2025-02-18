#include <QCoreApplication>
#include <qhttpserver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpServer>
#include <QTcpSocket>

// 定义一个映射用于存储每个用户名对应的客户端套接字
QMap<QString, QTcpSocket*> usernameToSocket;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        auto db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");


        // 打开数据库
        if (!db.open())
        {
            qWarning("users.db open failed~");
            return 0;
        }

        // 创建一个用户表
        QSqlQuery query(db);
        query.exec("PRAGMA foreign_keys = ON;");
        if (!query.exec(""
                        "CREATE TABLE IF NOT EXISTS users("
                        "user_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "user_name VARCHAR(20) UNIQUE, "
                        "user_password VARCHAR(20))"))
        {
            qWarning("create table users failed~");
        }

        // 插入用户（如果没有的话）
        if (!query.exec("INSERT OR IGNORE INTO users(user_name, user_password) VALUES('zxx', '123456')"))
        {
            qWarning("insert into users failed~");
        }

        // 创建一个用户信息表
        if (!query.exec(""
                        "CREATE TABLE IF NOT EXISTS users_information("
                        "uid INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "user_name VARCHAR(20) UNIQUE, "
                        "uname VARCHAR(255),"
                        "user_gender VARCHAR(10), user_age INT,"
                        "user_region VARCHAR(255),"
                        "avatar TEXT)"))
        {
            qWarning("create table users_information failed~");
        }

        // 创建好友表
        if (!query.exec(""
                        "CREATE TABLE IF NOT EXISTS friends("
                        "user_name_1 VARCHAR(20), "
                        "user_name_2 VARCHAR(20), "
                        "status VARCHAR(20), "
                        "PRIMARY KEY(user_name_1, user_name_2), "
                        "FOREIGN KEY(user_name_1) REFERENCES users(user_name) ON DELETE CASCADE, "
                        "FOREIGN KEY(user_name_2) REFERENCES users(user_name) ON DELETE CASCADE)"))
        {
            qWarning("create table friends failed~");
        }

        // 创建会话表
        if (!query.exec(
                "CREATE TABLE IF NOT EXISTS chat_sessions ("
                "session_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "user_1_id VARCHAR(20) NOT NULL, "
                "user_2_id VARCHAR(20) NOT NULL, "
                "created_at DATETIME DEFAULT (datetime('now', 'localtime')), "  // 使用本地时间
                "updated_at DATETIME DEFAULT (datetime('now', 'localtime')), "  // 使用本地时间
                "last_message_content TEXT, "
                "FOREIGN KEY(user_1_id) REFERENCES users(user_name) ON DELETE CASCADE, "
                "FOREIGN KEY(user_2_id) REFERENCES users(user_name) ON DELETE CASCADE)"
                ))
        {
            qWarning("Create table chat_sessions failed~");
        }

        // 创建聊天记录表
        if (!query.exec(
                "CREATE TABLE IF NOT EXISTS chat_messages ("
                "message_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "sender_id VARCHAR(20) NOT NULL, "
                "receiver_id VARCHAR(20) NOT NULL, "
                "message_content TEXT, "
                "message_type VARCHAR(50), "
                "chat_session_id INTEGER NOT NULL, "
                "sent_at DATETIME DEFAULT (datetime('now', 'localtime')), "     // 使用本地时间
                "updated_at DATETIME DEFAULT (datetime('now', 'localtime')), "  // 使用本地时间
                "FOREIGN KEY(sender_id) REFERENCES users(user_name) ON DELETE CASCADE, "
                "FOREIGN KEY(receiver_id) REFERENCES users(user_name) ON DELETE CASCADE, "
                "FOREIGN KEY(chat_session_id) REFERENCES chat_sessions(session_id) ON DELETE CASCADE)"
                ))
        {
            qWarning("Create table chat_messages failed~");
        }
    }



    // 创建Http服务器
    QHttpServer server;

    server.afterRequest([](QHttpServerResponse&& response)
                        {
                            response.setHeader("Content-Type", "application/json;utf-8");
                            return std::move(response);
                        });

    // 登录接口(API) /api/login
    server.route("/api/login", [](const QHttpServerRequest& request)
                 {
                     // 获取客户端提交的用户名和密码
                     QUrlQuery uquery = request.query();
                     auto username = uquery.queryItemValue("username");
                     auto password = uquery.queryItemValue("password");

                     // 账号密码校验
                     // 从数据库进行比对
                     QSqlQuery query;
                     query.prepare("SELECT COUNT(*) FROM users WHERE user_name = :username AND user_password = :password");
                     query.bindValue(":username", username);
                     query.bindValue(":password", password);

                     if (query.exec() && query.next())
                     {
                         int count = query.value(0).toInt();

                         if (count > 0)
                         {
                             // 登录成功
                             return QString(R"({"status":"success", "code":200, "message":"登录成功!"})");
                         }
                         else
                         {
                             // 用户名或密码错误
                             return QString(R"({"status":"failed", "code":200, "message":"用户名或密码不正确!"})");
                         }
                     }
                     else
                     {
                         // 查询执行失败，返回错误信息
                         return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败! %1"})").arg(query.lastError().text());
                     }
                 });


    // 注册接口(API) /api/signup
    server.route("/api/signup", [](const QHttpServerRequest& request)
                 {
                     // 获取客户端提交的用户名和密码
                     QUrlQuery uquery = request.query();
                     auto username = uquery.queryItemValue("username");
                     auto password = uquery.queryItemValue("password");

                     if (username.isEmpty() || password.isEmpty())
                     {
                         return QString(R"({"status":"failed", "code":400, "message":"用户名和密码不能为空!"})");
                     }

                     // 检查用户名是否已存在
                     QSqlQuery query;
                     query.prepare("SELECT COUNT(*) FROM users WHERE user_name = :username");
                     query.bindValue(":username", username);

                     if (query.exec() && query.next())
                     {
                         int count = query.value(0).toInt();

                         if (count > 0)
                         {
                             return QString(R"({"status":"repeat", "code":400, "message":"用户名已存在!"})");
                         }
                     }
                     else
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败! %1"})").arg(query.lastError().text());
                     }

                     // 插入新用户
                     query.prepare("INSERT INTO users(user_name, user_password) VALUES(:username, :password)");
                     query.bindValue(":username", username);
                     query.bindValue(":password", password);

                     if (query.exec())
                     {
                         return QString(R"({"status":"success", "code":200, "message":"注册成功!"})");
                     }
                     else
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"注册失败! %1"})").arg(query.lastError().text());
                     }
                 });

    // 修改用户信息接口(API) /api/profile
    server.route("/api/profile", [](const QHttpServerRequest& request)
                 {
                     QByteArray body = request.body();
                     QJsonDocument jsonDoc = QJsonDocument::fromJson(body);

                     if (jsonDoc.isNull() || !jsonDoc.isObject()) {
                         return QString(R"({"status":"failed", "code":400, "message":"无效的JSON数据!"})");
                     }

                     QJsonObject jsonObj = jsonDoc.object();
                     QString username = jsonObj["username"].toString();
                     QString uname = jsonObj["uname"].toString();
                     QString gender = jsonObj["gender"].toString();
                     int age = jsonObj["age"].toInt();
                     QString region = jsonObj["region"].toString();
                     QString avatar = jsonObj["avatar"].toString();

                     // 检查必填字段
                     if (username.isEmpty()) {
                         return QString(R"({"status":"failed", "code":400, "message":"用户名为必填项!"})");
                     }

                     if (uname.isEmpty())
                     {
                         return QString(R"({"status":"failed", "code":400, "message":"昵称为必填项!"})");
                     }

                     bool isGenderValid = (gender == "男" || gender == "女");
                     if (!isGenderValid)
                     {
                         return QString(R"({"status":"failed", "code":400, "message":"性别字段无效! 必须为 '男' 或 '女'"})");
                     }

                     // 检查用户是否存在
                     QSqlQuery query;
                     query.prepare("SELECT COUNT(*) FROM users WHERE user_name = :username");
                     query.bindValue(":username", username);

                     if (query.exec() && query.next())
                     {
                         int count = query.value(0).toInt();
                         if (count == 0)
                         {
                             return QString(R"({"status":"failed", "code":400, "message":"用户不存在!"})");
                         }
                     }
                     else
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败! %1"})").arg(query.lastError().text());
                     }

                     // 检查用户信息是否已存在
                     query.prepare("SELECT COUNT(*) FROM users_information WHERE user_name = :username");
                     query.bindValue(":username", username);

                     if (query.exec() && query.next())
                     {
                         int count = query.value(0).toInt();
                         if (count == 0)
                         {
                             // 插入新用户信息
                             query.prepare("INSERT INTO users_information(user_name, uname, user_gender, user_age, user_region, avatar) "
                                           "VALUES(:user_name, :uname, :user_gender, :user_age, :user_region, :avatar)");
                             query.bindValue(":user_name", username);
                             query.bindValue(":uname", uname);
                             query.bindValue(":user_gender", gender);
                             query.bindValue(":user_age", age);
                             query.bindValue(":user_region", region);
                             query.bindValue(":avatar", avatar);
                         }
                         else
                         {
                             // 更新用户信息
                             query.prepare("UPDATE users_information SET uname = :uname, user_gender = :user_gender, "
                                           "user_age = :user_age, user_region = :user_region, avatar = :avatar WHERE user_name = :user_name");
                             query.bindValue(":user_name", username);
                             query.bindValue(":uname", uname);
                             query.bindValue(":user_gender", gender);
                             query.bindValue(":user_age", age);
                             query.bindValue(":user_region", region);
                             query.bindValue(":avatar", avatar);
                         }
                     }

                     if (query.exec())
                     {
                         qInfo() << "用户 " << username << "更改个人信息";
                         return QString(R"({"status":"success", "code":200, "message":"用户信息更新成功!"})");
                     }
                     else
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"用户信息更新失败! %1"})").arg(query.lastError().text());
                     }
                 });


    // 获取用户信息接口(API) /api/getUserData
    server.route("/api/getUserData", [](const QHttpServerRequest& request)
                 {
                     QUrlQuery uquery = request.query();
                     auto username = uquery.queryItemValue("username");

                     if (username.isEmpty())
                     {
                         return QString(R"({"status":"failed", "code":400, "message":传递用户名为空!"})");
                     }

                     QSqlQuery query;
                     query.prepare("SELECT uname, user_gender, user_age, user_region, avatar FROM users_information WHERE user_name = :username");
                     query.bindValue(":username", username);

                     if (!query.exec())
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败!"})");
                     }

                     // 如果没有查询到数据
                     if (!query.next())
                     {
                         return QString(R"({"status":"failed", "code":404, "message":"用户信息未找到!"})");
                     }

                    // 将查询结果封装为 JSON 格式
                    QJsonObject userData;
                    userData["uname"] = query.value("uname").toString();
                    userData["user_gender"] = query.value("user_gender").toString();
                    userData["user_age"] = query.value("user_age").toInt();
                    userData["user_region"] = query.value("user_region").toString();
                    userData["avatar"] = query.value("avatar").toString();



                    // 将 JSON 对象转换为字符串
                    QJsonDocument doc(userData);

                    // 返回用户信息和状态
                    return QString(R"({"status":"success", "code":200, "message":"用户信息返回成功!", "data":)") + doc.toJson(QJsonDocument::Compact) + "}";

                 });

    // 查询好友接口(API) /api/addfriend
    server.route("/api/addfriend", [](const QHttpServerRequest& request)
                 {
                     // 获取客户端提交的好友名
                     QUrlQuery uquery = request.query();
                     auto friendName = uquery.queryItemValue("friendName");

                     // 从数据库进行比对
                     QSqlQuery query;
                     query.prepare("SELECT COUNT(*) FROM users WHERE user_name = :friendName");
                     query.bindValue(":friendName", friendName);


                     if (query.exec() && query.next())
                     {
                         int count = query.value(0).toInt();

                         if (count > 0)
                         {
                             // 登录成功
                             return QString(R"({"status":"success", "code":200, "message":"查询好友成功!"})");
                         }
                         else
                         {
                             // 用户名或密码错误
                             return QString(R"({"status":"failed", "code":200, "message":"用户名不存在!"})");
                         }
                     }
                     else
                     {
                         // 查询执行失败，返回错误信息
                         return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败! %1"})").arg(query.lastError().text());
                     }
                 });

    // 获取好友信息接口(API) /api/getSearchUserData
    server.route("/api/getSearchUserData", [](const QHttpServerRequest& request)
                 {
                     QUrlQuery uquery = request.query();
                     auto username = uquery.queryItemValue("username");


                     if (username.isEmpty())
                     {
                         return QString(R"({"status":"failed", "code":400, "message":传递用户名为空!"})");
                     }

                     QSqlQuery query;
                     query.prepare("SELECT uname, user_region, avatar FROM users_information WHERE user_name = :username");
                     query.bindValue(":username", username);

                     if (!query.exec())
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败!"})");
                     }

                     // 如果没有查询到数据
                     if (!query.next())
                     {
                         return QString(R"({"status":"failed", "code":404, "message":"用户信息未找到!"})");
                     }

                     // 将查询结果封装为 JSON 格式
                     QJsonObject userData;
                     userData["uname"] = query.value("uname").toString();
                     userData["user_region"] = query.value("user_region").toString();
                     userData["avatar"] = query.value("avatar").toString();

                     // 将 JSON 对象转换为字符串
                     QJsonDocument doc(userData);

                     // 返回用户信息和状态
                     return QString(R"({"status":"success", "code":200, "message":"用户信息返回成功!", "data":)") + doc.toJson(QJsonDocument::Compact) + "}";

                 });

    // 申请添加好友接口(API) /api/applytoadd
    server.route("/api/applytoadd", [](const QHttpServerRequest& request)
                 {
                     // 获取客户端提交的好友名
                     QUrlQuery uquery = request.query();
                     auto user_name_1 = uquery.queryItemValue("user_name_1");
                     auto user_name_2 = uquery.queryItemValue("user_name_2");

                     if (user_name_1.isEmpty() || user_name_2.isEmpty())
                     {
                         return QString(R"({"status":"failed", "code":400, "message":"当前登录用户名或添加好友用户名不能为空!"})");
                     }

                     // 检查好友关系是否已存在
                     QSqlQuery query;
                     query.prepare("SELECT status FROM friends WHERE (user_name_1 = :user_name_1 AND user_name_2 = :user_name_2) OR (user_name_1 = :user_name_2 AND user_name_2 = :user_name_1)");
                     query.bindValue(":user_name_1", user_name_1);
                     query.bindValue(":user_name_2", user_name_2);

                     if (query.exec() && query.next())
                     {
                         QString status = query.value(0).toString();

                         if (status == "apply")
                         {
                             // 返回已申请
                             return QString(R"({"status":"apply", "code":400, "message":"已申请添加对方为好友，等待对方确认!"})");
                         }
                         else if (status == "friend")
                         {
                             // 返回已是好友
                             return QString(R"({"status":"friend", "code":400, "message":"你们已经是好友!"})");
                         }
                         else if (status == "refuse")
                         {
                             // 返回对方拒绝
                             return QString(R"({"status":"refuse", "code":400, "message":"对方已经拒绝你的好友请求!"})");
                         }
                     }

                     // 如果没有找到记录，插入新的好友请求
                     query.prepare("INSERT INTO friends(user_name_1, user_name_2, status) VALUES(:user_name_1, :user_name_2, :status)");
                     query.bindValue(":user_name_1", user_name_1);
                     query.bindValue(":user_name_2", user_name_2);
                     query.bindValue(":status", "apply");

                     if (query.exec())
                     {
                         qInfo() << user_name_1 << "向" << "user_name_2" << "提出好友申请";
                         return QString(R"({"status":"success", "code":200, "message":"好友申请发送成功!"})");
                     }
                     else
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"好友关系更新失败! %1"})").arg(query.lastError().text());
                     }


                 });

    // 处理申请信息接口(API) /api/addverification
    server.route("/api/addverification", [](const QHttpServerRequest& request)
                 {
                     // 获取客户端提交的好友名
                     QUrlQuery uquery = request.query();
                     auto user_name_1 = uquery.queryItemValue("user_name_1");
                     auto user_name_2 = uquery.queryItemValue("user_name_2");
                     auto buttonText = uquery.queryItemValue("buttonText");


                     if (user_name_1.isEmpty() || user_name_2.isEmpty() || buttonText.isEmpty())
                     {
                         return QString(R"({"status":"failed", "code":400, "message":"当前登录用户名或添加好友用户名或按钮文本不能为空!"})");
                     }

                     // 检查好友关系是否已存在
                     QSqlQuery query;
                     query.prepare("SELECT status FROM friends WHERE (user_name_1 = :user_name_1 AND user_name_2 = :user_name_2) OR (user_name_1 = :user_name_2 AND user_name_2 = :user_name_1)");
                     query.bindValue(":user_name_1", user_name_1);
                     query.bindValue(":user_name_2", user_name_2);

                     if (query.exec() && query.next()) {
                         // 好友关系已存在，更新 status
                         QSqlQuery updateQuery;
                         updateQuery.prepare("UPDATE friends SET status = :status WHERE (user_name_1 = :user_name_1 AND user_name_2 = :user_name_2) OR (user_name_1 = :user_name_2 AND user_name_2 = :user_name_1)");
                         updateQuery.bindValue(":status", buttonText);
                         updateQuery.bindValue(":user_name_1", user_name_1);
                         updateQuery.bindValue(":user_name_2", user_name_2);
                         if (!updateQuery.exec()) {
                             qWarning() << "Failed to update friends status: " << updateQuery.lastError();
                             return QString(R"({"status":"failed", "code":500, "message":"好友关系状态更新失败! %1"})").arg(updateQuery.lastError().text());
                         }
                     }

                     if (buttonText == "friend") {
                         QSqlQuery query;

                         // 将新的聊天会话插入chat_sessions表
                         query.prepare("INSERT INTO chat_sessions (user_1_id, user_2_id) VALUES (:user_1_id, :user_2_id)");
                         query.bindValue(":user_1_id", user_name_1);
                         query.bindValue(":user_2_id", user_name_2);

                         if (!query.exec()) {
                             qWarning() << "Failed to insert new chat session: " << query.lastError();
                         } else {
                             qDebug() << "New chat session added successfully!";

                             // 检索新创建的聊天会话的session_id
                             int sessionId = query.lastInsertId().toInt();

                             // 在chat_messages表中插入默认消息
                             QSqlQuery messageQuery;
                             messageQuery.prepare("INSERT INTO chat_messages (chat_session_id, sender_id, receiver_id, message_content, message_type) "
                                                  "VALUES (:chat_session_id, :sender_id, :receiver_id, :message_content, :message_type)");
                             messageQuery.bindValue(":chat_session_id", sessionId);                      // 绑定 session_id
                             messageQuery.bindValue(":sender_id", user_name_2);                          // 绑定 sender_id
                             messageQuery.bindValue(":receiver_id", user_name_1);                        // 绑定 receiver_id
                             messageQuery.bindValue(":message_content", "我们已经成为好友，可以开始对话了。");  // 绑定 message_content
                             messageQuery.bindValue(":message_type", "text");                            // 绑定 message_type

                             if (!messageQuery.exec()) {
                                 qWarning() << "Failed to insert message into chat_messages: " << messageQuery.lastError();
                             } else {
                                 qDebug() << "Introductory message added successfully!";
                             }
                         }
                     }
                     else
                     {
                         qInfo() << "好友关系不存在";

                     }

                     if (query.exec())
                     {
                         qInfo() << user_name_1 <<  "通过好友申请";
                         return QString(R"({"status":"success", "code":200, "message":"好友申请发送成功!"})");
                     }
                     else
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"好友关系更新失败! %1"})").arg(query.lastError().text());
                     }
                 });

    // 获取好友信息接口(API) /api/getSearchUserData
    server.route("/api/getFriendRequests", [](const QHttpServerRequest& request)
                 {
                     QUrlQuery uquery = request.query();
                     auto username = uquery.queryItemValue("username");


                     if (username.isEmpty())
                     {
                         return QString(R"({"status":"failed", "code":400, "message":传递用户名为空!"})");
                     }

                     QSqlQuery query;
                     query.prepare("SELECT uname, user_region, avatar FROM users_information WHERE user_name = :username");
                     query.bindValue(":username", username);

                     if (!query.exec())
                     {
                         return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败!"})");
                     }

                     // 如果没有查询到数据
                     if (!query.next())
                     {
                         return QString(R"({"status":"failed", "code":404, "message":"用户信息未找到!"})");
                     }

                     // 将查询结果封装为 JSON 格式
                     QJsonObject userData;
                     userData["uname"] = query.value("uname").toString();
                     userData["user_region"] = query.value("user_region").toString();
                     userData["avatar"] = query.value("avatar").toString();


                     // 将 JSON 对象转换为字符串
                     QJsonDocument doc(userData);

                     // 返回用户信息和状态
                     return QString(R"({"status":"success", "code":200, "message":"用户信息返回成功!", "data":)") + doc.toJson(QJsonDocument::Compact) + "}";

                 });


    // 获取消息列表接口 (API) /api/fetchfriendlist
    server.route("/api/fetchfriendlist", [](const QHttpServerRequest& request) {
        QUrlQuery uquery = request.query();
        auto username = uquery.queryItemValue("username");

        if (username.isEmpty()) {
            return QString(R"({"status":"failed", "code":400, "message":"用户名为空!"})");
        }

        // 检查用户是否存在
        QSqlQuery userExistsQuery;
        userExistsQuery.prepare("SELECT user_id FROM users WHERE user_name = :username");
        userExistsQuery.bindValue(":username", username);
        if (!userExistsQuery.exec()) {
            qWarning() << "用户存在性查询失败:" << userExistsQuery.lastError().text();
            return QString(R"({"status":"failed", "code":500, "message":"用户查询失败!"})");
        }
        if (!userExistsQuery.next()) {
            return QString(R"({"status":"failed", "code":404, "message":"用户不存在!"})");
        }
        QString currentUserId = userExistsQuery.value("user_id").toString();

        // 查询当前用户的头像信息
        QSqlQuery currentUserAvatarQuery;
        currentUserAvatarQuery.prepare("SELECT avatar FROM users_information WHERE user_name = :username");
        currentUserAvatarQuery.bindValue(":username", username);
        if (!currentUserAvatarQuery.exec()) {
            qWarning() << "当前用户头像查询失败:" << currentUserAvatarQuery.lastError().text();
            return QString(R"({"status":"failed", "code":500, "message":"当前用户头像查询失败!"})");
        }
        QString currentUserAvatar;
        if (currentUserAvatarQuery.next()) {
            currentUserAvatar = currentUserAvatarQuery.value("avatar").toString();
        }

        // 获取去重后的好友列表
        QSqlQuery query;
        query.prepare(R"(
                        SELECT DISTINCT
                            CASE WHEN f.user_name_1 = :username THEN f.user_name_2 ELSE f.user_name_1 END AS friend_username
                        FROM friends f
                        WHERE (f.user_name_1 = :username OR f.user_name_2 = :username) AND f.status = 'friend'
        )");
        query.bindValue(":username", username);

        if (!query.exec()) {
            qWarning() << "好友列表查询失败:" << query.lastError().text();
            return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败!"})");
        }

        QStringList friendUsernames;
        while (query.next()) {
            friendUsernames.append(query.value("friend_username").toString());
        }

        if (friendUsernames.isEmpty()) {
            return QString(R"({"status":"success", "code":200, "message":"好友信息返回成功!", "data":[]})");
        }

        // 批量获取用户信息
        QSqlQuery userQuery;
        QString userQuerySql = QString("SELECT user_name, uname, avatar FROM users_information WHERE user_name IN (%1)")
                                   .arg(QStringList(friendUsernames.size(), "?").join(","));
        userQuery.prepare(userQuerySql);
        for (const QString &uname : friendUsernames) {
            userQuery.addBindValue(uname);
        }

        QMap<QString, QJsonObject> userInfoMap;
        if (!userQuery.exec()) {
            qWarning() << "用户信息查询失败:" << userQuery.lastError().text();
        } else {
            while (userQuery.next()) {
                QString user_name = userQuery.value("user_name").toString();
                QJsonObject info;
                info["user_name"] = userQuery.value("user_name").toString();
                info["uname"] = userQuery.value("uname").toString();
                info["avatar"] = userQuery.value("avatar").toString();
                userInfoMap[user_name] = info;
            }
        }

        // 批量获取最新消息
        QSqlQuery messageQuery;
        QString messageQuerySql = QString(R"(
            WITH ranked_messages AS (
                SELECT
                    m.message_content AS content,
                    m.sent_at AS timestamp,
                    CASE
                        WHEN cs.user_1_id = ? THEN cs.user_2_id
                        ELSE cs.user_1_id
                    END AS friend_username,
                    ROW_NUMBER() OVER (
                        PARTITION BY CASE
                            WHEN cs.user_1_id = ? THEN cs.user_2_id
                            ELSE cs.user_1_id
                        END
                        ORDER BY m.sent_at DESC
                    ) AS rn
                FROM chat_messages m
                JOIN chat_sessions cs ON m.chat_session_id = cs.session_id
                WHERE ? IN (cs.user_1_id, cs.user_2_id)
            )
            SELECT content, timestamp, friend_username
            FROM ranked_messages
            WHERE rn = 1 AND friend_username IN (%1)
        )").arg(QStringList(friendUsernames.size(), "?").join(","));

        messageQuery.prepare(messageQuerySql);
        // 绑定前三个 ? 为 username
        messageQuery.addBindValue(username);
        messageQuery.addBindValue(username);
        messageQuery.addBindValue(username);
        // 绑定 IN 子句中的用户名
        for (const QString &uname : friendUsernames) {
            messageQuery.addBindValue(uname);
        }

        QMap<QString, QJsonObject> messageMap;
        if (!messageQuery.exec()) {
            qWarning() << "最新消息查询失败:" << messageQuery.lastError().text();
        } else {
            while (messageQuery.next()) {
                QString friendUsername = messageQuery.value("friend_username").toString();
                QJsonObject msg;
                msg["last_message"] = messageQuery.value("content").toString();
                msg["last_message_time"] = messageQuery.value("timestamp").toString();
                messageMap[friendUsername] = msg;
            }
        }

        // 构建响应数据
        QJsonArray friendsArray;
        for (const QString &friendUsername : friendUsernames) {
            if (!userInfoMap.contains(friendUsername)) {
                continue; // 跳过无效好友
            }

            QJsonObject friendData = userInfoMap[friendUsername];
            friendData["friend_username"] = friendUsername;

            if (messageMap.contains(friendUsername)) {
                QJsonObject msg = messageMap[friendUsername];
                friendData["last_message"] = msg["last_message"];
                friendData["last_message_time"] = msg["last_message_time"];
            } else {
                friendData["last_message"] = "";
                friendData["last_message_time"] = "";
            }

            friendsArray.append(friendData);
        }

        return QString(R"({"status":"success", "code":200, "message":"好友信息返回成功!", "data":%1})")
            .arg(QString(QJsonDocument(friendsArray).toJson(QJsonDocument::Compact)));
    });

    // 获取好友列表接口 (API) /api/getFriendsList
    server.route("/api/getFriendsList", [](const QHttpServerRequest& request) {
        QUrlQuery uquery = request.query();
        auto username = uquery.queryItemValue("username");

        if (username.isEmpty())
        {
            return QString(R"({"status":"failed", "code":400, "message":"用户名为空!"})");
        }
        // 检查用户是否存在
        auto checkUserExists = [](const QString& username)
        {
            QSqlQuery userExistsQuery;
            userExistsQuery.prepare("SELECT user_id FROM users WHERE user_name = :username");
            userExistsQuery.bindValue(":username", username);
            if (!userExistsQuery.exec())
            {
                qWarning() << "用户存在性查询失败:" << userExistsQuery.lastError().text();
                return QString();
            }
            if (!userExistsQuery.next())
            {
                return QString();
            }
            return userExistsQuery.value("user_id").toString();
        };

        QString currentUserId = checkUserExists(username);
        if (currentUserId.isEmpty())
        {
            return QString(R"({"status":"failed", "code":404, "message":"用户不存在!"})");
        }

        // 获取去重后的好友列表
        QSqlQuery query;
        query.prepare(R"(
                    SELECT DISTINCT
                        CASE WHEN f.user_name_1 = :username THEN f.user_name_2 ELSE f.user_name_1 END AS friend_username
                    FROM friends f
                    WHERE (f.user_name_1 = :username OR f.user_name_2 = :username) AND f.status = 'friend'
        )");

        query.bindValue(":username", username);
        if (!query.exec())
        {
            qWarning() << "好友列表查询失败:" << query.lastError().text();
            return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败!"})");
        }
        QStringList friendUsernames;
        while (query.next()) {
            friendUsernames.append(query.value("friend_username").toString());
        }

        if (friendUsernames.isEmpty())
        {
            return QString(R"({"status":"success", "code":200, "message":"好友信息返回成功!", "data":[]})");
        }

        // 批量获取用户信息
        QSqlQuery userQuery;
        QString userQuerySql = QString("SELECT user_name, uname, avatar, user_gender, user_age, user_region FROM users_information WHERE user_name IN (%1)")
                                   .arg(QStringList(friendUsernames.size(), "?").join(","));
        userQuery.prepare(userQuerySql);
        for (const QString &uname : friendUsernames)
        {
            userQuery.addBindValue(uname);
        }
        QMap<QString, QJsonObject> userInfoMap;
        if (!userQuery.exec())
        {
            qWarning() << "用户信息查询失败:" << userQuery.lastError().text();
        }
        else
        {
            while (userQuery.next())
            {
                QString user_name = userQuery.value("user_name").toString();
                QJsonObject info;
                info["uname"] = userQuery.value("uname").toString();
                info["user_gender"] = userQuery.value("user_gender").toString();
                info["user_age"] = userQuery.value("user_age").toString();
                info["user_region"] = userQuery.value("user_region").toString();
                info["avatar"] = userQuery.value("avatar").toString();
                userInfoMap[user_name] = info;
            }
        }

        // 构建响应数据
        QJsonArray friendsArray;
        for (const QString &friendUsername : friendUsernames)
        {
            if (!userInfoMap.contains(friendUsername))
            {
                continue; // 跳过无效好友
            }
            QJsonObject friendData = userInfoMap[friendUsername];
            friendData["friend_username"] = friendUsername;
            friendsArray.append(friendData);
        }
        return QString(R"({"status":"success", "code":200, "message":"好友信息返回成功!", "data":%1})")
            .arg(QString(QJsonDocument(friendsArray).toJson(QJsonDocument::Compact)));
    });

    // 处理获取好友请求列表(API) /api/fetchfriendrequests
    server.route("/api/fetchfriendrequests", [](const QHttpServerRequest& request) {
        QUrlQuery uquery = request.query();
        auto username = uquery.queryItemValue("username");

        // 检查用户名是否为空
        if (username.isEmpty()) {
            return QString(R"({"status":"failed", "code":400, "message":"用户名为空!"})");
        }
        // 检查用户是否存在
        auto checkUserExists = [](const QString& username) {
            QSqlQuery userExistsQuery;
            userExistsQuery.prepare("SELECT user_id FROM users WHERE user_name = :username");
            userExistsQuery.bindValue(":username", username);
            if (!userExistsQuery.exec()) {
                qWarning() << "用户存在性查询失败:" << userExistsQuery.lastError().text();
                return QString();
            }
            if (!userExistsQuery.next()) {
                return QString();
            }
            return userExistsQuery.value("user_id").toString();
        };
        QString currentUserId = checkUserExists(username);
        if (currentUserId.isEmpty()) {
            return QString(R"({"status":"failed", "code":404, "message":"用户不存在!"})");
        }
        // 查询好友请求列表
        QSqlQuery query;
        query.prepare(R"(
            SELECT
                CASE WHEN fr.user_name_1 = :username THEN fr.user_name_2 ELSE fr.user_name_1 END AS requester_username,
                ui.uname,
                ui.avatar,
                fr.status
            FROM
                friends fr
            JOIN
                users_information ui ON (CASE WHEN fr.user_name_1 = :username THEN fr.user_name_2 ELSE fr.user_name_1 END) = ui.user_name
            WHERE
                (fr.user_name_1 = :username OR fr.user_name_2 = :username)
        )");
        query.bindValue(":username", username);
        if (!query.exec()) {
            qWarning() << "好友请求列表查询失败:" << query.lastError().text();
            return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败!"})");
        }
        QJsonArray requestsArray;
        while (query.next()) {
            QJsonObject requestObj;
            requestObj["username"] = query.value("requester_username").toString();
            requestObj["uname"] = query.value("uname").toString();
            requestObj["avatar"] = query.value("avatar").toString();
            requestObj["status"] = query.value("status").toString();
            requestsArray.append(requestObj);
        }

        // 构建响应数据
        QJsonObject responseObj;
        responseObj["status"] = "success";
        responseObj["code"] = 200;
        responseObj["message"] = "好友请求信息返回成功!";
        responseObj["data"] = requestsArray;

        return QString(QJsonDocument(responseObj).toJson(QJsonDocument::Compact));
    });


    // 接受者验证(API) /api/receiver
    server.route("/api/receiver", [](const QHttpServerRequest& request) {
        QUrlQuery uquery = request.query();
        auto user_name_1 = uquery.queryItemValue("user_name_1");
        auto user_name_2 = uquery.queryItemValue("user_name_2");

        // 检查用户名是否为空
        if (user_name_1.isEmpty() || user_name_2.isEmpty()) {
            return QString(R"({"status":"failed", "code":400, "message":"用户名为空!"})");
        }

        // 检查申请者和接收者用户名是否正确
        QSqlQuery query;
        query.prepare("SELECT status FROM friends WHERE user_name_1 = :user_name_1 AND user_name_2 = :user_name_2");
        query.bindValue(":user_name_1", user_name_1);
        query.bindValue(":user_name_2", user_name_2);

        if (query.exec()) {
            // 检查是否有结果
            if (query.next()) {
                return QString(R"({"status":"success", "code":200})");
            } else {
                return QString(R"({"status":"failed", "code":404, "message":"未找到指定用户名组合的记录"})");
            }
        } else {
            return QString(R"({"status":"failed", "code":500, "message":"%1"})").arg(query.lastError().text());
        }
    });

    // 处理消息的接口 (API) /api/sendMessage
    server.route("/api/sendMessage", [](const QHttpServerRequest& request) {
        QByteArray body = request.body();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(body);

        if (jsonDoc.isNull() || !jsonDoc.isObject()) {
            return QString(R"({"status":"failed", "code":400, "message":"无效的JSON数据!"})");
        }

        QJsonObject jsonObj = jsonDoc.object();
        QString sender = jsonObj["sender"].toString();
        QString receiver = jsonObj["receiver"].toString();
        QString content = jsonObj["content"].toString();
        QString timestamp = jsonObj["timestamp"].toString();

        // 检查聊天会话是否存在
        QSqlQuery sessionQuery;
        sessionQuery.prepare("SELECT session_id FROM chat_sessions WHERE (user_1_id = :user1 AND user_2_id = :user2) OR (user_1_id = :user2 AND user_2_id = :user1)");
        sessionQuery.bindValue(":user1", sender);
        sessionQuery.bindValue(":user2", receiver);

        QString sessionId;
        if (sessionQuery.exec() && sessionQuery.next()) {
            sessionId = sessionQuery.value("session_id").toString();
        } else {
            // 创建新的聊天会话
            sessionQuery.prepare("INSERT INTO chat_sessions (user_1_id, user_2_id, created_at, updated_at) "
                                 "VALUES (:user1, :user2, :created_at, :updated_at)");
            sessionQuery.bindValue(":user1", sender);
            sessionQuery.bindValue(":user2", receiver);
            sessionQuery.bindValue(":created_at", timestamp);
            sessionQuery.bindValue(":updated_at", timestamp);

            if (sessionQuery.exec()) {
                sessionId = sessionQuery.lastInsertId().toString();
            } else {
                return QString(R"({"status":"failed", "code":500, "message":"聊天会话创建失败! %1"})").arg(sessionQuery.lastError().text());
            }
        }

        // 插入消息到数据库
        QSqlQuery messageQuery;
        messageQuery.prepare("INSERT INTO chat_messages (chat_session_id, sender_id, receiver_id, message_content, message_type, sent_at) "
                             "VALUES (:chat_session_id, :sender_id, :receiver_id, :message_content, :message_type, :sent_at)");
        messageQuery.bindValue(":chat_session_id", sessionId);
        messageQuery.bindValue(":sender_id", sender);
        messageQuery.bindValue(":receiver_id", receiver);
        messageQuery.bindValue(":message_content", content);
        messageQuery.bindValue(":message_type", "text");
        messageQuery.bindValue(":sent_at", timestamp);

        if (messageQuery.exec()) {
            return QString(R"({"status":"success", "code":200, "message":"消息发送成功!"})");
        } else {
            return QString(R"({"status":"failed", "code":500, "message":"消息保存失败! %1"})").arg(messageQuery.lastError().text());
        }
    });


    // 在服务器端代码中添加以下路由
    server.route("/api/getChatHistory", [](const QHttpServerRequest& request) {
        QUrlQuery uquery = request.query();
        auto user1 = uquery.queryItemValue("user1");
        auto user2 = uquery.queryItemValue("user2");

        if (user1.isEmpty() || user2.isEmpty()) {
            return QString(R"({"status":"failed", "code":400, "message":"用户名不能为空!"})");
        }

        QSqlQuery query;
        query.prepare("SELECT sender_id, message_content, sent_at FROM chat_messages "
                      "WHERE (sender_id = :user1 AND receiver_id = :user2) OR (sender_id = :user2 AND receiver_id = :user1) "
                      "ORDER BY sent_at ASC");
        query.bindValue(":user1", user1);
        query.bindValue(":user2", user2);

        if (!query.exec()) {
            return QString(R"({"status":"failed", "code":500, "message":"数据库查询失败: %1"})").arg(query.lastError().text());
        }

        QJsonArray messagesArray;
        while (query.next()) {
            QJsonObject messageObj;
            messageObj["sender"] = query.value("sender_id").toString();
            messageObj["content"] = query.value("message_content").toString();
            messageObj["timestamp"] = query.value("sent_at").toString();
            messagesArray.append(messageObj);
        }

        QJsonObject responseObj;
        responseObj["status"] = "success";
        responseObj["code"] = 200;
        responseObj["message"] = "聊天记录获取成功!";
        responseObj["data"] = messagesArray;

        return QString(QJsonDocument(responseObj).toJson(QJsonDocument::Compact));
    });

    // 保存聊天内容到数据库
    server.route("/api/saveMessage", [](const QHttpServerRequest& request) {
        QUrlQuery query(request.url().query());
        QString chatSessionId = query.queryItemValue("chat_session_id");
        QString senderId = query.queryItemValue("sender_id");
        QString receiverId = query.queryItemValue("receiver_id");
        QString messageContent = query.queryItemValue("message_content");
        QString messageType = query.queryItemValue("message_type");
        QString sentAt = query.queryItemValue("sent_at");

        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO chat_messages (chat_session_id, sender_id, receiver_id, message_content, message_type, sent_at) "
                            "VALUES (:chat_session_id, :sender_id, :receiver_id, :message_content, :message_type, :sent_at)");
        insertQuery.bindValue(":chat_session_id", chatSessionId);
        insertQuery.bindValue(":sender_id", senderId);
        insertQuery.bindValue(":receiver_id", receiverId);
        insertQuery.bindValue(":message_content", messageContent);
        insertQuery.bindValue(":message_type", messageType);
        insertQuery.bindValue(":sent_at", sentAt);

        QJsonObject response;
        if (insertQuery.exec()) {
            // 更新会话表的最后消息内容
            QSqlQuery updateSessionQuery(db);
            updateSessionQuery.prepare("UPDATE chat_sessions SET last_message_content = :last_message_content, updated_at = :updated_at WHERE session_id = :session_id");
            updateSessionQuery.bindValue(":last_message_content", messageContent);
            updateSessionQuery.bindValue(":updated_at", sentAt);
            updateSessionQuery.bindValue(":session_id", chatSessionId);
            updateSessionQuery.exec();

            response["status"] = "success";
        } else {
            response["status"] = "error";
            response["message"] = insertQuery.lastError().text();
        }

        QJsonDocument doc(response);
        return QHttpServerResponse(doc.toJson());
    });

    // 创建聊天会话（如果不存在）
    server.route("/api/checkChatSession", [](const QHttpServerRequest& request) {
        QUrlQuery query(request.url().query());
        QString user1 = query.queryItemValue("user1");
        QString user2 = query.queryItemValue("user2");

        // 检查 user1 是否等于 user2
        if (user1 == user2) {
            QJsonObject response;
            response["status"] = "error";
            response["message"] = "user1 and user2 cannot be the same.";
            QJsonDocument doc(response);
            return QHttpServerResponse(doc.toJson());
        }

        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery checkQuery(db);
        checkQuery.prepare("SELECT session_id FROM chat_sessions WHERE (user_1_id = :user1 AND user_2_id = :user2) OR (user_1_id = :user2 AND user_2_id = :user1)");
        checkQuery.bindValue(":user1", user1);
        checkQuery.bindValue(":user2", user2);

        QJsonObject response;
        if (checkQuery.exec() && checkQuery.next()) {
            response["status"] = "exists";
            response["session_id"] = checkQuery.value("session_id").toString();
        } else {
            // 创建新的聊天会话
            QSqlQuery insertQuery(db);
            insertQuery.prepare("INSERT INTO chat_sessions (user_1_id, user_2_id) VALUES (:user1, :user2)");
            insertQuery.bindValue(":user1", user1);
            insertQuery.bindValue(":user2", user2);

            if (insertQuery.exec()) {
                response["status"] = "created";
                response["session_id"] = QString::number(insertQuery.lastInsertId().toInt());
            } else {
                response["status"] = "error";
                response["message"] = insertQuery.lastError().text();
            }
        }

        QJsonDocument doc(response);
        return QHttpServerResponse(doc.toJson());
    });


    server.listen(QHostAddress::Any, 80);   // 服务器开始监听连接


    // ================== TCP服务器部分 ==================
    QTcpServer tcpServer;
    QList<QTcpSocket*> tcpClients;  // 保存所有连接的客户端

    // 监听TCP端口（例如 82)
    if (!tcpServer.listen(QHostAddress::Any, 82))
    {
        qWarning() << "TCP Server could not start:" << tcpServer.errorString();
        return -1;
    }
    else
    {
        qInfo() << "TCP Server started on port 82";
    }

    // 处理新TCP连接
    QObject::connect(&tcpServer, &QTcpServer::newConnection, [&]() {
        QTcpSocket *clientSocket = tcpServer.nextPendingConnection();
        tcpClients.append(clientSocket);
        qInfo() << "New TCP client connected:" << clientSocket->peerAddress().toString();

        // 接收数据
        QObject::connect(clientSocket, &QTcpSocket::readyRead, [clientSocket, &tcpClients]() {
            QByteArray data = clientSocket->readAll();


            // 解析JSON数据
            QJsonDocument doc = QJsonDocument::fromJson(data);
            if (doc.isNull() || !doc.isObject()) {
                qWarning() << "无效的JSON数据";
                return;
            }

            QJsonObject jsonObj = doc.object();
            QString sender = jsonObj["sender"].toString();
            QString receiver = jsonObj["receiver"].toString();
            QString content = jsonObj["content"].toString();

            qInfo() << sender << "向" << receiver << "发送了" << content;

            // 保存发送者的套接字信息
            usernameToSocket[sender] = clientSocket;

            // 查找接收者的套接字
            if (usernameToSocket.contains(receiver)) {
                QTcpSocket *receiverSocket = usernameToSocket[receiver];
                // 发送消息给接收者
                receiverSocket->write(data);
            } else {
                qWarning() << "接收者未连接:" << receiver;
            }

            QString response = QString("%1").arg(QString(data));
            clientSocket->write(response.toUtf8());
        });

        // 处理断开连接
        QObject::connect(clientSocket, &QTcpSocket::disconnected, [clientSocket, &tcpClients]() {
            qInfo() << "Client disconnected";
            tcpClients.removeOne(clientSocket);
            clientSocket->deleteLater();
        });
    });

    return a.exec();
}
