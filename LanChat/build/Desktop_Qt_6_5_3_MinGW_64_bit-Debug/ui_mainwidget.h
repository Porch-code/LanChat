/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout_5;
    QStackedWidget *verticalStackedWidget;
    QWidget *verticalStackedWidgetPage1;
    QVBoxLayout *verticalLayout_4;
    QWidget *FriendMessageBar;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_FriendProFile;
    QLabel *label_FriendName;
    QSpacerItem *horizontalSpacer_2;
    QListView *listView_Chat;
    QWidget *EditMessageBar;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Emoji;
    QPushButton *pushButton_SendFile;
    QSpacerItem *horizontalSpacer_7;
    QWidget *SendMessageBar;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_SendMsg;
    QTextEdit *textEdit_Msg;
    QWidget *verticalStackedWidgetPage2;
    QListView *listView_FriendApply;
    QWidget *FriendMessageBar_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_FriendProFile_3;
    QLabel *label_FriendName_3;
    QSpacerItem *horizontalSpacer_14;
    QWidget *verticalStackedWidgetPage3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_7;
    QGridLayout *gridLayout_3;
    QLabel *label_data_FriendGender;
    QLabel *label_data_FriendRegion;
    QLabel *label_data_FriendAge;
    QLabel *label_data_FriendName;
    QLabel *label_data_FriendProFile;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_FriendVoice;
    QPushButton *pushButton_FriendVideo;
    QWidget *verticalStackedWidgetPage4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_home_ProFile;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_home_text;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_SearchFriend;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_Search;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_AddFriend;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Reduce;
    QPushButton *pushButton_increase;
    QPushButton *pushButton_Close;
    QListView *listView_Users;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_ProFile;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_Message;
    QPushButton *pushButton_Friend;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_Setting;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(1008, 723);
        MainWidget->setMinimumSize(QSize(880, 660));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/logo_3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidget->setWindowIcon(icon);
        gridLayout_5 = new QGridLayout(MainWidget);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setHorizontalSpacing(1);
        gridLayout_5->setVerticalSpacing(0);
        gridLayout_5->setContentsMargins(0, 0, 9, 9);
        verticalStackedWidget = new QStackedWidget(MainWidget);
        verticalStackedWidget->setObjectName("verticalStackedWidget");
        verticalStackedWidget->setMinimumSize(QSize(0, 623));
        verticalStackedWidget->setLineWidth(0);
        verticalStackedWidgetPage1 = new QWidget();
        verticalStackedWidgetPage1->setObjectName("verticalStackedWidgetPage1");
        verticalLayout_4 = new QVBoxLayout(verticalStackedWidgetPage1);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        FriendMessageBar = new QWidget(verticalStackedWidgetPage1);
        FriendMessageBar->setObjectName("FriendMessageBar");
        FriendMessageBar->setMinimumSize(QSize(0, 50));
        horizontalLayout_5 = new QHBoxLayout(FriendMessageBar);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_FriendProFile = new QLabel(FriendMessageBar);
        label_FriendProFile->setObjectName("label_FriendProFile");
        label_FriendProFile->setMinimumSize(QSize(30, 30));
        label_FriendProFile->setMaximumSize(QSize(30, 30));

        horizontalLayout_5->addWidget(label_FriendProFile);

        label_FriendName = new QLabel(FriendMessageBar);
        label_FriendName->setObjectName("label_FriendName");
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        label_FriendName->setFont(font);

        horizontalLayout_5->addWidget(label_FriendName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(FriendMessageBar);

        listView_Chat = new QListView(verticalStackedWidgetPage1);
        listView_Chat->setObjectName("listView_Chat");
        listView_Chat->setMinimumSize(QSize(0, 400));
        listView_Chat->setMaximumSize(QSize(16777215, 400));

        verticalLayout_4->addWidget(listView_Chat);

        EditMessageBar = new QWidget(verticalStackedWidgetPage1);
        EditMessageBar->setObjectName("EditMessageBar");
        gridLayout = new QGridLayout(EditMessageBar);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_Emoji = new QPushButton(EditMessageBar);
        pushButton_Emoji->setObjectName("pushButton_Emoji");
        pushButton_Emoji->setMinimumSize(QSize(30, 30));
        pushButton_Emoji->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/emoji.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Emoji->setIcon(icon1);
        pushButton_Emoji->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_Emoji);

        pushButton_SendFile = new QPushButton(EditMessageBar);
        pushButton_SendFile->setObjectName("pushButton_SendFile");
        pushButton_SendFile->setMinimumSize(QSize(30, 30));
        pushButton_SendFile->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SendFile->setIcon(icon2);
        pushButton_SendFile->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_SendFile);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_7 = new QSpacerItem(500, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        SendMessageBar = new QWidget(EditMessageBar);
        SendMessageBar->setObjectName("SendMessageBar");
        horizontalLayout_3 = new QHBoxLayout(SendMessageBar);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_SendMsg = new QPushButton(SendMessageBar);
        pushButton_SendMsg->setObjectName("pushButton_SendMsg");
        pushButton_SendMsg->setMinimumSize(QSize(70, 35));
        pushButton_SendMsg->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(pushButton_SendMsg);


        gridLayout->addWidget(SendMessageBar, 4, 0, 1, 1);

        textEdit_Msg = new QTextEdit(EditMessageBar);
        textEdit_Msg->setObjectName("textEdit_Msg");
        textEdit_Msg->setLineWidth(0);

        gridLayout->addWidget(textEdit_Msg, 2, 0, 1, 1);


        verticalLayout_4->addWidget(EditMessageBar);

        verticalStackedWidget->addWidget(verticalStackedWidgetPage1);
        verticalStackedWidgetPage2 = new QWidget();
        verticalStackedWidgetPage2->setObjectName("verticalStackedWidgetPage2");
        listView_FriendApply = new QListView(verticalStackedWidgetPage2);
        listView_FriendApply->setObjectName("listView_FriendApply");
        listView_FriendApply->setGeometry(QRect(-10, 50, 631, 621));
        FriendMessageBar_2 = new QWidget(verticalStackedWidgetPage2);
        FriendMessageBar_2->setObjectName("FriendMessageBar_2");
        FriendMessageBar_2->setGeometry(QRect(0, 0, 631, 50));
        FriendMessageBar_2->setMinimumSize(QSize(0, 50));
        horizontalLayout_10 = new QHBoxLayout(FriendMessageBar_2);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_FriendProFile_3 = new QLabel(FriendMessageBar_2);
        label_FriendProFile_3->setObjectName("label_FriendProFile_3");
        label_FriendProFile_3->setMinimumSize(QSize(30, 30));
        label_FriendProFile_3->setMaximumSize(QSize(30, 30));

        horizontalLayout_10->addWidget(label_FriendProFile_3);

        label_FriendName_3 = new QLabel(FriendMessageBar_2);
        label_FriendName_3->setObjectName("label_FriendName_3");
        QFont font1;
        font1.setPointSize(12);
        label_FriendName_3->setFont(font1);

        horizontalLayout_10->addWidget(label_FriendName_3);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_14);

        verticalStackedWidget->addWidget(verticalStackedWidgetPage2);
        verticalStackedWidgetPage3 = new QWidget();
        verticalStackedWidgetPage3->setObjectName("verticalStackedWidgetPage3");
        gridLayout_2 = new QGridLayout(verticalStackedWidgetPage3);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        verticalSpacer_7 = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_7, 2, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label_data_FriendGender = new QLabel(verticalStackedWidgetPage3);
        label_data_FriendGender->setObjectName("label_data_FriendGender");
        QFont font2;
        font2.setPointSize(11);
        label_data_FriendGender->setFont(font2);
        label_data_FriendGender->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_data_FriendGender, 3, 2, 1, 1);

        label_data_FriendRegion = new QLabel(verticalStackedWidgetPage3);
        label_data_FriendRegion->setObjectName("label_data_FriendRegion");
        label_data_FriendRegion->setFont(font2);
        label_data_FriendRegion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_data_FriendRegion, 5, 2, 1, 1);

        label_data_FriendAge = new QLabel(verticalStackedWidgetPage3);
        label_data_FriendAge->setObjectName("label_data_FriendAge");
        label_data_FriendAge->setFont(font2);
        label_data_FriendAge->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_data_FriendAge, 4, 2, 1, 1);

        label_data_FriendName = new QLabel(verticalStackedWidgetPage3);
        label_data_FriendName->setObjectName("label_data_FriendName");
        label_data_FriendName->setFont(font2);
        label_data_FriendName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_data_FriendName->setMargin(0);

        gridLayout_3->addWidget(label_data_FriendName, 2, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 4, 1, 2);

        label_data_FriendProFile = new QLabel(verticalStackedWidgetPage3);
        label_data_FriendProFile->setObjectName("label_data_FriendProFile");
        label_data_FriendProFile->setMinimumSize(QSize(200, 200));
        label_data_FriendProFile->setMaximumSize(QSize(200, 200));

        gridLayout_4->addWidget(label_data_FriendProFile, 1, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 50, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 3, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 50, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 3, 6, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_8, 0, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_13, 1, 2, 1, 1);

        pushButton_FriendVoice = new QPushButton(verticalStackedWidgetPage3);
        pushButton_FriendVoice->setObjectName("pushButton_FriendVoice");
        pushButton_FriendVoice->setMinimumSize(QSize(170, 35));
        pushButton_FriendVoice->setMaximumSize(QSize(170, 16777215));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        pushButton_FriendVoice->setFont(font3);

        gridLayout_4->addWidget(pushButton_FriendVoice, 3, 1, 1, 1);

        pushButton_FriendVideo = new QPushButton(verticalStackedWidgetPage3);
        pushButton_FriendVideo->setObjectName("pushButton_FriendVideo");
        pushButton_FriendVideo->setMinimumSize(QSize(170, 35));
        pushButton_FriendVideo->setMaximumSize(QSize(170, 16777215));
        pushButton_FriendVideo->setFont(font3);

        gridLayout_4->addWidget(pushButton_FriendVideo, 3, 5, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 1);

        verticalStackedWidget->addWidget(verticalStackedWidgetPage3);
        verticalStackedWidgetPage4 = new QWidget();
        verticalStackedWidgetPage4->setObjectName("verticalStackedWidgetPage4");
        layoutWidget = new QWidget(verticalStackedWidgetPage4);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(200, 130, 202, 295));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_home_ProFile = new QLabel(layoutWidget);
        label_home_ProFile->setObjectName("label_home_ProFile");
        label_home_ProFile->setMinimumSize(QSize(200, 200));
        label_home_ProFile->setMaximumSize(QSize(200, 200));

        verticalLayout_7->addWidget(label_home_ProFile);

        verticalSpacer_4 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_4);

        label_home_text = new QLabel(layoutWidget);
        label_home_text->setObjectName("label_home_text");
        label_home_text->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_home_text);

        verticalStackedWidget->addWidget(verticalStackedWidgetPage4);

        gridLayout_5->addWidget(verticalStackedWidget, 1, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 5, -1, 10);
        horizontalSpacer_4 = new QSpacerItem(250, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_SearchFriend = new QPushButton(MainWidget);
        pushButton_SearchFriend->setObjectName("pushButton_SearchFriend");
        pushButton_SearchFriend->setMinimumSize(QSize(25, 25));
        pushButton_SearchFriend->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SearchFriend->setIcon(icon3);

        horizontalLayout_4->addWidget(pushButton_SearchFriend);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        lineEdit_Search = new QLineEdit(MainWidget);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setMinimumSize(QSize(250, 0));
        lineEdit_Search->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_4->addWidget(lineEdit_Search);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pushButton_AddFriend = new QPushButton(MainWidget);
        pushButton_AddFriend->setObjectName("pushButton_AddFriend");
        pushButton_AddFriend->setMinimumSize(QSize(25, 25));
        pushButton_AddFriend->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/customer-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_AddFriend->setIcon(icon4);

        horizontalLayout_4->addWidget(pushButton_AddFriend);

        horizontalSpacer_3 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_Reduce = new QPushButton(MainWidget);
        pushButton_Reduce->setObjectName("pushButton_Reduce");
        pushButton_Reduce->setMinimumSize(QSize(30, 25));
        pushButton_Reduce->setMaximumSize(QSize(30, 25));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/reduce.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reduce->setIcon(icon5);

        horizontalLayout_4->addWidget(pushButton_Reduce);

        pushButton_increase = new QPushButton(MainWidget);
        pushButton_increase->setObjectName("pushButton_increase");
        pushButton_increase->setMinimumSize(QSize(30, 25));
        pushButton_increase->setMaximumSize(QSize(30, 25));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_increase->setIcon(icon6);

        horizontalLayout_4->addWidget(pushButton_increase);

        pushButton_Close = new QPushButton(MainWidget);
        pushButton_Close->setObjectName("pushButton_Close");
        pushButton_Close->setMinimumSize(QSize(30, 25));
        pushButton_Close->setMaximumSize(QSize(30, 25));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Close->setIcon(icon7);

        horizontalLayout_4->addWidget(pushButton_Close);


        gridLayout_5->addLayout(horizontalLayout_4, 0, 1, 1, 2);

        listView_Users = new QListView(MainWidget);
        listView_Users->setObjectName("listView_Users");
        listView_Users->setMinimumSize(QSize(300, 600));
        listView_Users->setMaximumSize(QSize(300, 670));

        gridLayout_5->addWidget(listView_Users, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 0, 10, -1);
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        label_ProFile = new QLabel(MainWidget);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(60, 60));
        label_ProFile->setMaximumSize(QSize(60, 60));
        label_ProFile->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_ProFile);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        pushButton_Message = new QPushButton(MainWidget);
        pushButton_Message->setObjectName("pushButton_Message");
        pushButton_Message->setMinimumSize(QSize(50, 50));
        pushButton_Message->setMaximumSize(QSize(50, 50));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/images/message-comments-fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Message->setIcon(icon8);
        pushButton_Message->setIconSize(QSize(30, 30));

        verticalLayout_2->addWidget(pushButton_Message);

        pushButton_Friend = new QPushButton(MainWidget);
        pushButton_Friend->setObjectName("pushButton_Friend");
        pushButton_Friend->setMinimumSize(QSize(50, 50));
        pushButton_Friend->setMaximumSize(QSize(50, 50));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/images/customer-fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Friend->setIcon(icon9);
        pushButton_Friend->setIconSize(QSize(30, 30));

        verticalLayout_2->addWidget(pushButton_Friend);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_8);

        verticalSpacer_3 = new QSpacerItem(20, 450, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        pushButton_Setting = new QPushButton(MainWidget);
        pushButton_Setting->setObjectName("pushButton_Setting");
        pushButton_Setting->setMinimumSize(QSize(50, 50));
        pushButton_Setting->setMaximumSize(QSize(50, 50));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Setting->setIcon(icon10);
        pushButton_Setting->setIconSize(QSize(30, 30));

        verticalLayout_2->addWidget(pushButton_Setting);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 2, 1);


        retranslateUi(MainWidget);

        verticalStackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "LanChat", nullptr));
        label_FriendProFile->setText(QString());
        label_FriendName->setText(QCoreApplication::translate("MainWidget", "Name", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Emoji->setToolTip(QCoreApplication::translate("MainWidget", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Emoji->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_SendFile->setToolTip(QCoreApplication::translate("MainWidget", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_SendFile->setText(QString());
        pushButton_SendMsg->setText(QCoreApplication::translate("MainWidget", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        label_FriendProFile_3->setText(QString());
        label_FriendName_3->setText(QCoreApplication::translate("MainWidget", "Name", nullptr));
        label_data_FriendGender->setText(QCoreApplication::translate("MainWidget", "\346\200\247\345\210\253", nullptr));
        label_data_FriendRegion->setText(QCoreApplication::translate("MainWidget", "\345\234\260\345\214\272", nullptr));
        label_data_FriendAge->setText(QCoreApplication::translate("MainWidget", "\345\271\264\351\276\204", nullptr));
        label_data_FriendName->setText(QCoreApplication::translate("MainWidget", "\345\247\223\345\220\215", nullptr));
        label_data_FriendProFile->setText(QCoreApplication::translate("MainWidget", "TextLabel", nullptr));
        pushButton_FriendVoice->setText(QCoreApplication::translate("MainWidget", "\350\257\255\351\237\263\351\200\232\350\257\235", nullptr));
        pushButton_FriendVideo->setText(QCoreApplication::translate("MainWidget", "\350\247\206\351\242\221\351\200\232\350\257\235", nullptr));
        label_home_ProFile->setText(QString());
        label_home_text->setText(QCoreApplication::translate("MainWidget", "\346\254\242\350\277\216\344\275\277\347\224\250LanChat", nullptr));
        pushButton_SearchFriend->setText(QString());
        lineEdit_Search->setPlaceholderText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242", nullptr));
        pushButton_AddFriend->setText(QString());
        pushButton_Reduce->setText(QString());
        pushButton_increase->setText(QString());
        pushButton_Close->setText(QString());
        label_ProFile->setText(QCoreApplication::translate("MainWidget", "ProFile", nullptr));
        pushButton_Message->setText(QString());
        pushButton_Friend->setText(QString());
        pushButton_Setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
