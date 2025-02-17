/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Close;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_Password;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBox_Authorize;
    QLabel *label_ProFile;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_UserName;
    QPushButton *pushButton_Login;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(320, 448);
        Login->setMinimumSize(QSize(320, 448));
        Login->setMaximumSize(QSize(320, 448));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Close = new QPushButton(Login);
        pushButton_Close->setObjectName("pushButton_Close");
        pushButton_Close->setMinimumSize(QSize(30, 30));
        pushButton_Close->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_Close);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 2, 1, 1);

        lineEdit_Password = new QLineEdit(Login);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setMinimumSize(QSize(0, 40));
        lineEdit_Password->setMaximumSize(QSize(16777215, 40));
        lineEdit_Password->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_Password, 6, 1, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 16, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 7, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 9, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 1, 1, 1);

        checkBox_Authorize = new QCheckBox(Login);
        checkBox_Authorize->setObjectName("checkBox_Authorize");

        gridLayout->addWidget(checkBox_Authorize, 8, 1, 1, 3);

        label_ProFile = new QLabel(Login);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(75, 75));
        label_ProFile->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(label_ProFile, 2, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(verticalSpacer_6, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        lineEdit_UserName = new QLineEdit(Login);
        lineEdit_UserName->setObjectName("lineEdit_UserName");
        lineEdit_UserName->setMinimumSize(QSize(0, 40));
        lineEdit_UserName->setMaximumSize(QSize(16777215, 40));
        lineEdit_UserName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_UserName, 4, 1, 1, 3);

        pushButton_Login = new QPushButton(Login);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setMinimumSize(QSize(0, 35));
        pushButton_Login->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(pushButton_Login, 10, 1, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 90, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        gridLayout->addItem(verticalSpacer_5, 11, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Login);

        pushButton_Login->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        pushButton_Close->setText(QString());
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        checkBox_Authorize->setText(QCoreApplication::translate("Login", "\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\346\234\215\345\212\241\345\215\217\350\256\256\345\222\214\351\232\220\347\247\201\344\277\235\346\212\244", nullptr));
        label_ProFile->setText(QString());
        lineEdit_UserName->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
