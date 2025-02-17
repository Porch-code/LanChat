/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
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

class Ui_register
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *register)
    {
        if (register->objectName().isEmpty())
            register->setObjectName("register");
        register->resize(320, 448);
        register->setMinimumSize(QSize(320, 448));
        register->setMaximumSize(QSize(320, 448));
        verticalLayout = new QVBoxLayout(register);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(register);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(30, 29, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(register);
        label->setObjectName("label");
        label->setMinimumSize(QSize(75, 75));
        label->setMaximumSize(QSize(75, 75));

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(register);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_2->addWidget(lineEdit_2, 3, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        lineEdit = new QLineEdit(register);
        lineEdit->setObjectName("lineEdit");

        gridLayout_2->addWidget(lineEdit, 2, 1, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(register);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_2->addWidget(pushButton_2, 5, 1, 1, 3);

        checkBox = new QCheckBox(register);
        checkBox->setObjectName("checkBox");

        gridLayout_2->addWidget(checkBox, 4, 1, 1, 3);

        verticalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(register);

        QMetaObject::connectSlotsByName(register);
    } // setupUi

    void retranslateUi(QWidget *register)
    {
        register->setWindowTitle(QCoreApplication::translate("register", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("register", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("register", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("register", "PushButton", nullptr));
        checkBox->setText(QCoreApplication::translate("register", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register: public Ui_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
