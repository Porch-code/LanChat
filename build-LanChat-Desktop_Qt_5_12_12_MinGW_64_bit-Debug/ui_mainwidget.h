/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QTextBrowser *textBrowser;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Bold;
    QPushButton *pushButton_Italic;
    QPushButton *pushButton_UnderLine;
    QPushButton *pushButton_FontColor;
    QPushButton *pushButton_SendFile;
    QPushButton *pushButton_SaveFile;
    QPushButton *pushButton_ClearMsg;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox_Size;
    QTextEdit *textEdit_Msg;
    QTableView *tableView_Users;
    QPushButton *pushButton_SendMsg;
    QPushButton *pushButton_Close;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidget->setWindowIcon(icon);
        textBrowser = new QTextBrowser(MainWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 20, 461, 331));
        horizontalLayoutWidget = new QWidget(MainWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(270, 360, 221, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Bold = new QPushButton(horizontalLayoutWidget);
        pushButton_Bold->setObjectName(QString::fromUtf8("pushButton_Bold"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Bold->setIcon(icon1);
        pushButton_Bold->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_Bold);

        pushButton_Italic = new QPushButton(horizontalLayoutWidget);
        pushButton_Italic->setObjectName(QString::fromUtf8("pushButton_Italic"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Italic->setIcon(icon2);
        pushButton_Italic->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_Italic);

        pushButton_UnderLine = new QPushButton(horizontalLayoutWidget);
        pushButton_UnderLine->setObjectName(QString::fromUtf8("pushButton_UnderLine"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_UnderLine->setIcon(icon3);
        pushButton_UnderLine->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_UnderLine);

        pushButton_FontColor = new QPushButton(horizontalLayoutWidget);
        pushButton_FontColor->setObjectName(QString::fromUtf8("pushButton_FontColor"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_FontColor->setIcon(icon4);
        pushButton_FontColor->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_FontColor);

        pushButton_SendFile = new QPushButton(horizontalLayoutWidget);
        pushButton_SendFile->setObjectName(QString::fromUtf8("pushButton_SendFile"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SendFile->setIcon(icon5);
        pushButton_SendFile->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_SendFile);

        pushButton_SaveFile = new QPushButton(horizontalLayoutWidget);
        pushButton_SaveFile->setObjectName(QString::fromUtf8("pushButton_SaveFile"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SaveFile->setIcon(icon6);
        pushButton_SaveFile->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_SaveFile);

        pushButton_ClearMsg = new QPushButton(horizontalLayoutWidget);
        pushButton_ClearMsg->setObjectName(QString::fromUtf8("pushButton_ClearMsg"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ClearMsg->setIcon(icon7);
        pushButton_ClearMsg->setAutoDefault(true);

        horizontalLayout->addWidget(pushButton_ClearMsg);

        horizontalLayoutWidget_2 = new QWidget(MainWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 360, 231, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        fontComboBox = new QFontComboBox(horizontalLayoutWidget_2);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout_2->addWidget(fontComboBox);

        comboBox_Size = new QComboBox(horizontalLayoutWidget_2);
        comboBox_Size->setObjectName(QString::fromUtf8("comboBox_Size"));

        horizontalLayout_2->addWidget(comboBox_Size);

        textEdit_Msg = new QTextEdit(MainWidget);
        textEdit_Msg->setObjectName(QString::fromUtf8("textEdit_Msg"));
        textEdit_Msg->setGeometry(QRect(30, 430, 461, 111));
        tableView_Users = new QTableView(MainWidget);
        tableView_Users->setObjectName(QString::fromUtf8("tableView_Users"));
        tableView_Users->setGeometry(QRect(510, 20, 251, 521));
        pushButton_SendMsg = new QPushButton(MainWidget);
        pushButton_SendMsg->setObjectName(QString::fromUtf8("pushButton_SendMsg"));
        pushButton_SendMsg->setGeometry(QRect(400, 550, 89, 24));
        pushButton_Close = new QPushButton(MainWidget);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(290, 550, 89, 24));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "LanChat", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Bold->setToolTip(QApplication::translate("MainWidget", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Bold->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Italic->setToolTip(QApplication::translate("MainWidget", "\346\226\234\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Italic->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_UnderLine->setToolTip(QApplication::translate("MainWidget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_UnderLine->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_FontColor->setToolTip(QApplication::translate("MainWidget", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_FontColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_SendFile->setToolTip(QApplication::translate("MainWidget", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SendFile->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_SaveFile->setToolTip(QApplication::translate("MainWidget", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SaveFile->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_ClearMsg->setToolTip(QApplication::translate("MainWidget", "\346\270\205\347\220\206", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_ClearMsg->setText(QString());
        comboBox_Size->setCurrentText(QString());
        pushButton_SendMsg->setText(QApplication::translate("MainWidget", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        pushButton_Close->setText(QApplication::translate("MainWidget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
