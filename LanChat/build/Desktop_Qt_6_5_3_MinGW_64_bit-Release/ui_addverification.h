/********************************************************************************
** Form generated from reading UI file 'addverification.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVERIFICATION_H
#define UI_ADDVERIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddVerification
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ProFile;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_Name;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_Region;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout;
    QPushButton *pushButton_refuse;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_agree;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *AddVerification)
    {
        if (AddVerification->objectName().isEmpty())
            AddVerification->setObjectName("AddVerification");
        AddVerification->resize(300, 160);
        AddVerification->setMinimumSize(QSize(300, 150));
        AddVerification->setMaximumSize(QSize(300, 160));
        gridLayout_2 = new QGridLayout(AddVerification);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 0, 0, -1);
        label_ProFile = new QLabel(AddVerification);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(80, 80));
        label_ProFile->setMaximumSize(QSize(80, 80));

        horizontalLayout->addWidget(label_ProFile);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, -1, -1, -1);
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label_Name = new QLabel(AddVerification);
        label_Name->setObjectName("label_Name");

        verticalLayout->addWidget(label_Name);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        label_Region = new QLabel(AddVerification);
        label_Region->setObjectName("label_Region");

        verticalLayout->addWidget(label_Region);

        verticalSpacer_5 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        pushButton_refuse = new QPushButton(AddVerification);
        pushButton_refuse->setObjectName("pushButton_refuse");
        pushButton_refuse->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(pushButton_refuse, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        pushButton_agree = new QPushButton(AddVerification);
        pushButton_agree->setObjectName("pushButton_agree");
        pushButton_agree->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(pushButton_agree, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);


        retranslateUi(AddVerification);

        QMetaObject::connectSlotsByName(AddVerification);
    } // setupUi

    void retranslateUi(QWidget *AddVerification)
    {
        AddVerification->setWindowTitle(QCoreApplication::translate("AddVerification", "Form", nullptr));
        label_ProFile->setText(QCoreApplication::translate("AddVerification", "profile", nullptr));
        label_Name->setText(QCoreApplication::translate("AddVerification", "name", nullptr));
        label_Region->setText(QCoreApplication::translate("AddVerification", "name", nullptr));
        pushButton_refuse->setText(QCoreApplication::translate("AddVerification", "\346\213\222\347\273\235", nullptr));
        pushButton_agree->setText(QCoreApplication::translate("AddVerification", "\345\220\214\346\204\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddVerification: public Ui_AddVerification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVERIFICATION_H
