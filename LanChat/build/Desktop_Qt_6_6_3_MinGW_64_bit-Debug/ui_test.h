/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ProFile;
    QPushButton *pushButton_Message;
    QPushButton *pushButton_Friend;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_Setting;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_SearchFriend;
    QLineEdit *lineEdit_Search;
    QPushButton *pushButton_AddFriend;
    QSpacerItem *horizontalSpacer_3;
    QTableView *tableView_Users;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_FriendProFile;
    QLabel *label_FriendName;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_Soild;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Bold;
    QPushButton *pushButton_Italic;
    QPushButton *pushButton_UnderLine;
    QPushButton *pushButton_FontColor;
    QPushButton *pushButton_SendFile;
    QPushButton *pushButton_SaveFile;
    QPushButton *pushButton_ClearMsg;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox_Size;
    QTextEdit *textEdit_Msg;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_SendMsg;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName("Test");
        Test->resize(880, 660);
        Test->setMinimumSize(QSize(880, 660));
        Test->setMaximumSize(QSize(880, 660));
        gridLayout_2 = new QGridLayout(Test);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 0, -1, -1);
        label_ProFile = new QLabel(Test);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(50, 50));
        label_ProFile->setMaximumSize(QSize(50, 50));
        label_ProFile->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(label_ProFile);

        pushButton_Message = new QPushButton(Test);
        pushButton_Message->setObjectName("pushButton_Message");
        pushButton_Message->setMinimumSize(QSize(30, 30));
        pushButton_Message->setMaximumSize(QSize(30, 30));

        verticalLayout_2->addWidget(pushButton_Message);

        pushButton_Friend = new QPushButton(Test);
        pushButton_Friend->setObjectName("pushButton_Friend");
        pushButton_Friend->setMinimumSize(QSize(30, 30));
        pushButton_Friend->setMaximumSize(QSize(30, 30));

        verticalLayout_2->addWidget(pushButton_Friend);

        verticalSpacer_3 = new QSpacerItem(20, 500, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        pushButton_Setting = new QPushButton(Test);
        pushButton_Setting->setObjectName("pushButton_Setting");
        pushButton_Setting->setMinimumSize(QSize(30, 30));
        pushButton_Setting->setMaximumSize(QSize(30, 30));

        verticalLayout_2->addWidget(pushButton_Setting);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 9, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(3, 30, -1, -1);
        pushButton_SearchFriend = new QPushButton(Test);
        pushButton_SearchFriend->setObjectName("pushButton_SearchFriend");
        pushButton_SearchFriend->setMinimumSize(QSize(25, 25));
        pushButton_SearchFriend->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(pushButton_SearchFriend);

        lineEdit_Search = new QLineEdit(Test);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setMinimumSize(QSize(150, 0));
        lineEdit_Search->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_4->addWidget(lineEdit_Search);

        pushButton_AddFriend = new QPushButton(Test);
        pushButton_AddFriend->setObjectName("pushButton_AddFriend");
        pushButton_AddFriend->setMinimumSize(QSize(25, 25));
        pushButton_AddFriend->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(pushButton_AddFriend);

        horizontalSpacer_3 = new QSpacerItem(650, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 1, 1, 3);

        tableView_Users = new QTableView(Test);
        tableView_Users->setObjectName("tableView_Users");
        tableView_Users->setMinimumSize(QSize(300, 700));
        tableView_Users->setMaximumSize(QSize(300, 700));

        gridLayout_2->addWidget(tableView_Users, 1, 1, 8, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_FriendProFile = new QLabel(Test);
        label_FriendProFile->setObjectName("label_FriendProFile");
        label_FriendProFile->setMinimumSize(QSize(30, 30));
        label_FriendProFile->setMaximumSize(QSize(30, 30));

        horizontalLayout_5->addWidget(label_FriendProFile);

        label_FriendName = new QLabel(Test);
        label_FriendName->setObjectName("label_FriendName");

        horizontalLayout_5->addWidget(label_FriendName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 3, 1, 1);

        textBrowser = new QTextBrowser(Test);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(0, 400));

        gridLayout_2->addWidget(textBrowser, 2, 3, 1, 1);

        textBrowser_Soild = new QTextBrowser(Test);
        textBrowser_Soild->setObjectName("textBrowser_Soild");
        textBrowser_Soild->setMinimumSize(QSize(0, 4));
        textBrowser_Soild->setMaximumSize(QSize(16777215, 4));

        gridLayout_2->addWidget(textBrowser_Soild, 3, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_Bold = new QPushButton(Test);
        pushButton_Bold->setObjectName("pushButton_Bold");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Bold->setIcon(icon);
        pushButton_Bold->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_Bold);

        pushButton_Italic = new QPushButton(Test);
        pushButton_Italic->setObjectName("pushButton_Italic");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Italic->setIcon(icon1);
        pushButton_Italic->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_Italic);

        pushButton_UnderLine = new QPushButton(Test);
        pushButton_UnderLine->setObjectName("pushButton_UnderLine");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_UnderLine->setIcon(icon2);
        pushButton_UnderLine->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_UnderLine);

        pushButton_FontColor = new QPushButton(Test);
        pushButton_FontColor->setObjectName("pushButton_FontColor");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_FontColor->setIcon(icon3);
        pushButton_FontColor->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_FontColor);

        pushButton_SendFile = new QPushButton(Test);
        pushButton_SendFile->setObjectName("pushButton_SendFile");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SendFile->setIcon(icon4);
        pushButton_SendFile->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_SendFile);

        pushButton_SaveFile = new QPushButton(Test);
        pushButton_SaveFile->setObjectName("pushButton_SaveFile");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SaveFile->setIcon(icon5);
        pushButton_SaveFile->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_SaveFile);

        pushButton_ClearMsg = new QPushButton(Test);
        pushButton_ClearMsg->setObjectName("pushButton_ClearMsg");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ClearMsg->setIcon(icon6);
        pushButton_ClearMsg->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_ClearMsg);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        fontComboBox = new QFontComboBox(Test);
        fontComboBox->setObjectName("fontComboBox");

        horizontalLayout_2->addWidget(fontComboBox);

        comboBox_Size = new QComboBox(Test);
        comboBox_Size->setObjectName("comboBox_Size");

        horizontalLayout_2->addWidget(comboBox_Size);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 5, 3, 1, 1);

        textEdit_Msg = new QTextEdit(Test);
        textEdit_Msg->setObjectName("textEdit_Msg");

        gridLayout_2->addWidget(textEdit_Msg, 6, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_SendMsg = new QPushButton(Test);
        pushButton_SendMsg->setObjectName("pushButton_SendMsg");
        pushButton_SendMsg->setMinimumSize(QSize(70, 35));
        pushButton_SendMsg->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(pushButton_SendMsg);


        gridLayout_2->addLayout(horizontalLayout_3, 7, 3, 2, 1);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 8, 2, 1, 1);


        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QWidget *Test)
    {
        Test->setWindowTitle(QCoreApplication::translate("Test", "Form", nullptr));
        label_ProFile->setText(QCoreApplication::translate("Test", "ProFile", nullptr));
        pushButton_Message->setText(QString());
        pushButton_Friend->setText(QString());
        pushButton_Setting->setText(QString());
        pushButton_SearchFriend->setText(QString());
        pushButton_AddFriend->setText(QString());
        label_FriendProFile->setText(QString());
        label_FriendName->setText(QCoreApplication::translate("Test", "Name", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Bold->setToolTip(QCoreApplication::translate("Test", "\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Bold->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_Italic->setToolTip(QCoreApplication::translate("Test", "\346\226\234\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Italic->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_UnderLine->setToolTip(QCoreApplication::translate("Test", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_UnderLine->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_FontColor->setToolTip(QCoreApplication::translate("Test", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_FontColor->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_SendFile->setToolTip(QCoreApplication::translate("Test", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_SendFile->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_SaveFile->setToolTip(QCoreApplication::translate("Test", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_SaveFile->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_ClearMsg->setToolTip(QCoreApplication::translate("Test", "\346\270\205\347\220\206", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_ClearMsg->setText(QString());
        comboBox_Size->setCurrentText(QString());
        pushButton_SendMsg->setText(QCoreApplication::translate("Test", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
