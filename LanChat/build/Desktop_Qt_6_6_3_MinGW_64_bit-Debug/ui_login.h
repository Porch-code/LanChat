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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Reduce;
    QPushButton *pushButton_increase;
    QPushButton *pushButton_Close;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton_Register;
    QLineEdit *lineEdit_UserName;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_Password;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_7;
    QCheckBox *checkBox_Authorize;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Login;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_ProFile;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(800, 600);
        Login->setMinimumSize(QSize(800, 600));
        Login->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/logo_3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        horizontalLayoutWidget = new QWidget(Login);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 801, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(748, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Reduce = new QPushButton(horizontalLayoutWidget);
        pushButton_Reduce->setObjectName("pushButton_Reduce");
        pushButton_Reduce->setMinimumSize(QSize(30, 25));
        pushButton_Reduce->setMaximumSize(QSize(30, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/reduce.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reduce->setIcon(icon1);
        pushButton_Reduce->setIconSize(QSize(17, 17));

        horizontalLayout->addWidget(pushButton_Reduce);

        pushButton_increase = new QPushButton(horizontalLayoutWidget);
        pushButton_increase->setObjectName("pushButton_increase");
        pushButton_increase->setMinimumSize(QSize(30, 25));
        pushButton_increase->setMaximumSize(QSize(30, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_increase->setIcon(icon2);
        pushButton_increase->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(pushButton_increase);

        pushButton_Close = new QPushButton(horizontalLayoutWidget);
        pushButton_Close->setObjectName("pushButton_Close");
        pushButton_Close->setMinimumSize(QSize(30, 25));
        pushButton_Close->setMaximumSize(QSize(30, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Close->setIcon(icon3);
        pushButton_Close->setIconSize(QSize(17, 17));

        horizontalLayout->addWidget(pushButton_Close);

        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(440, 100, 316, 438));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 1, 2, 1, 1);

        pushButton_Register = new QPushButton(layoutWidget);
        pushButton_Register->setObjectName("pushButton_Register");
        pushButton_Register->setMinimumSize(QSize(0, 35));
        pushButton_Register->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(pushButton_Register, 12, 1, 1, 3);

        lineEdit_UserName = new QLineEdit(layoutWidget);
        lineEdit_UserName->setObjectName("lineEdit_UserName");
        lineEdit_UserName->setMinimumSize(QSize(0, 40));
        lineEdit_UserName->setMaximumSize(QSize(16777215, 40));
        lineEdit_UserName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEdit_UserName, 4, 1, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 3, 1, 1);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setMinimumSize(QSize(0, 40));
        lineEdit_Password->setMaximumSize(QSize(16777215, 40));
        lineEdit_Password->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEdit_Password, 6, 1, 1, 3);

        verticalSpacer_5 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(verticalSpacer_5, 13, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_7, 11, 2, 1, 1);

        checkBox_Authorize = new QCheckBox(layoutWidget);
        checkBox_Authorize->setObjectName("checkBox_Authorize");

        gridLayout->addWidget(checkBox_Authorize, 8, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        pushButton_Login = new QPushButton(layoutWidget);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setMinimumSize(QSize(0, 35));
        pushButton_Login->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(pushButton_Login, 10, 1, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 7, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 9, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        label_ProFile = new QLabel(layoutWidget);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(75, 75));
        label_ProFile->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(label_ProFile, 2, 2, 1, 1);

        QWidget::setTabOrder(pushButton_Reduce, pushButton_Close);
        QWidget::setTabOrder(pushButton_Close, lineEdit_UserName);
        QWidget::setTabOrder(lineEdit_UserName, lineEdit_Password);
        QWidget::setTabOrder(lineEdit_Password, checkBox_Authorize);
        QWidget::setTabOrder(checkBox_Authorize, pushButton_Login);
        QWidget::setTabOrder(pushButton_Login, pushButton_Register);

        retranslateUi(Login);

        pushButton_Register->setDefault(false);
        pushButton_Login->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        pushButton_Reduce->setText(QString());
        pushButton_increase->setText(QString());
        pushButton_Close->setText(QString());
        pushButton_Register->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        lineEdit_UserName->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        checkBox_Authorize->setText(QCoreApplication::translate("Login", "\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\346\234\215\345\212\241\345\215\217\350\256\256\345\222\214\351\232\220\347\247\201\344\277\235\346\212\244", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label_ProFile->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
