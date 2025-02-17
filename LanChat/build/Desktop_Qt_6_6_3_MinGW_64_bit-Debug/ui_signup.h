/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Password_2;
    QLabel *label_ProFile;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_Register;
    QLineEdit *lineEdit_Password;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *lineEdit_UserName;
    QPushButton *pushButton_Return;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QWidget *layoutWidget_1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Reduce;
    QPushButton *pushButton_increase;
    QPushButton *pushButton_Close;

    void setupUi(QWidget *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(800, 600);
        Signup->setMinimumSize(QSize(800, 600));
        Signup->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/logo_3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Signup->setWindowIcon(icon);
        layoutWidget = new QWidget(Signup);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(440, 100, 320, 437));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_Password_2 = new QLineEdit(layoutWidget);
        lineEdit_Password_2->setObjectName("lineEdit_Password_2");
        lineEdit_Password_2->setMinimumSize(QSize(0, 40));
        lineEdit_Password_2->setMaximumSize(QSize(16777215, 40));
        lineEdit_Password_2->setTabletTracking(false);
        lineEdit_Password_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEdit_Password_2, 9, 1, 1, 3);

        label_ProFile = new QLabel(layoutWidget);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(75, 75));
        label_ProFile->setMaximumSize(QSize(75, 75));

        gridLayout->addWidget(label_ProFile, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 4, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(verticalSpacer_5, 14, 2, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_7, 12, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 6, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 3, 1, 1);

        pushButton_Register = new QPushButton(layoutWidget);
        pushButton_Register->setObjectName("pushButton_Register");
        pushButton_Register->setMinimumSize(QSize(0, 35));
        pushButton_Register->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(pushButton_Register, 11, 1, 1, 3);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setMinimumSize(QSize(0, 40));
        lineEdit_Password->setMaximumSize(QSize(16777215, 40));
        lineEdit_Password->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEdit_Password, 7, 1, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 10, 2, 1, 1);

        lineEdit_UserName = new QLineEdit(layoutWidget);
        lineEdit_UserName->setObjectName("lineEdit_UserName");
        lineEdit_UserName->setMinimumSize(QSize(0, 40));
        lineEdit_UserName->setMaximumSize(QSize(16777215, 40));
        lineEdit_UserName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lineEdit_UserName, 5, 1, 1, 3);

        pushButton_Return = new QPushButton(layoutWidget);
        pushButton_Return->setObjectName("pushButton_Return");
        pushButton_Return->setMinimumSize(QSize(0, 35));
        pushButton_Return->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(pushButton_Return, 13, 1, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 8, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 1, 2, 1, 1);

        lineEdit_UserName->raise();
        pushButton_Register->raise();
        label_ProFile->raise();
        pushButton_Return->raise();
        lineEdit_Password->raise();
        lineEdit_Password_2->raise();
        layoutWidget_1 = new QWidget(Signup);
        layoutWidget_1->setObjectName("layoutWidget_1");
        layoutWidget_1->setGeometry(QRect(0, 0, 801, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget_1);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(718, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Reduce = new QPushButton(layoutWidget_1);
        pushButton_Reduce->setObjectName("pushButton_Reduce");
        pushButton_Reduce->setMinimumSize(QSize(30, 25));
        pushButton_Reduce->setMaximumSize(QSize(30, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/reduce.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reduce->setIcon(icon1);
        pushButton_Reduce->setIconSize(QSize(17, 17));

        horizontalLayout->addWidget(pushButton_Reduce);

        pushButton_increase = new QPushButton(layoutWidget_1);
        pushButton_increase->setObjectName("pushButton_increase");
        pushButton_increase->setMinimumSize(QSize(30, 25));
        pushButton_increase->setMaximumSize(QSize(30, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/square.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_increase->setIcon(icon2);
        pushButton_increase->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(pushButton_increase);

        pushButton_Close = new QPushButton(layoutWidget_1);
        pushButton_Close->setObjectName("pushButton_Close");
        pushButton_Close->setMinimumSize(QSize(30, 25));
        pushButton_Close->setMaximumSize(QSize(30, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Close->setIcon(icon3);
        pushButton_Close->setIconSize(QSize(17, 17));

        horizontalLayout->addWidget(pushButton_Close);

        QWidget::setTabOrder(pushButton_Reduce, pushButton_Close);
        QWidget::setTabOrder(pushButton_Close, lineEdit_UserName);
        QWidget::setTabOrder(lineEdit_UserName, lineEdit_Password);
        QWidget::setTabOrder(lineEdit_Password, lineEdit_Password_2);
        QWidget::setTabOrder(lineEdit_Password_2, pushButton_Register);
        QWidget::setTabOrder(pushButton_Register, pushButton_Return);

        retranslateUi(Signup);

        pushButton_Register->setDefault(false);
        pushButton_Return->setDefault(false);


        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QWidget *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "Signup", nullptr));
        lineEdit_Password_2->setPlaceholderText(QCoreApplication::translate("Signup", "\350\257\267\347\241\256\345\256\232\345\257\206\347\240\201", nullptr));
        label_ProFile->setText(QString());
        pushButton_Register->setText(QCoreApplication::translate("Signup", "\346\263\250\345\206\214", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("Signup", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        lineEdit_UserName->setPlaceholderText(QCoreApplication::translate("Signup", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton_Return->setText(QCoreApplication::translate("Signup", "\350\277\224\345\233\236", nullptr));
        pushButton_Reduce->setText(QString());
        pushButton_increase->setText(QString());
        pushButton_Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
