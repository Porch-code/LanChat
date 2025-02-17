/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

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

class Ui_AddFriend
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_AddFriend;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ProFile;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_Name;
    QLabel *label_Region;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *AddFriend)
    {
        if (AddFriend->objectName().isEmpty())
            AddFriend->setObjectName("AddFriend");
        AddFriend->resize(300, 160);
        AddFriend->setMinimumSize(QSize(300, 150));
        AddFriend->setMaximumSize(QSize(300, 160));
        gridLayout_2 = new QGridLayout(AddFriend);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        pushButton_AddFriend = new QPushButton(AddFriend);
        pushButton_AddFriend->setObjectName("pushButton_AddFriend");
        pushButton_AddFriend->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(pushButton_AddFriend, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 0, 0, -1);
        label_ProFile = new QLabel(AddFriend);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(80, 80));
        label_ProFile->setMaximumSize(QSize(80, 80));

        horizontalLayout->addWidget(label_ProFile);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, -1, -1, -1);
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label_Name = new QLabel(AddFriend);
        label_Name->setObjectName("label_Name");

        verticalLayout->addWidget(label_Name);

        label_Region = new QLabel(AddFriend);
        label_Region->setObjectName("label_Region");

        verticalLayout->addWidget(label_Region);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(AddFriend);

        QMetaObject::connectSlotsByName(AddFriend);
    } // setupUi

    void retranslateUi(QWidget *AddFriend)
    {
        AddFriend->setWindowTitle(QCoreApplication::translate("AddFriend", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        pushButton_AddFriend->setText(QCoreApplication::translate("AddFriend", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        label_ProFile->setText(QCoreApplication::translate("AddFriend", "profile", nullptr));
        label_Name->setText(QCoreApplication::translate("AddFriend", "name", nullptr));
        label_Region->setText(QCoreApplication::translate("AddFriend", "region", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriend: public Ui_AddFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
