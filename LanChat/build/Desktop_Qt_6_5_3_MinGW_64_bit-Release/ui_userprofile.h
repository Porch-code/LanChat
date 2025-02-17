/********************************************************************************
** Form generated from reading UI file 'userprofile.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILE_H
#define UI_USERPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserProFile
{
public:
    QGridLayout *gridLayout_2;
    QWidget *FirstWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_ProFile;
    QLabel *label_DIsplayUname;
    QSpacerItem *verticalSpacer;
    QWidget *SecondWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_RegionEdit;
    QSpinBox *spinBox_Age;
    QLabel *label_More;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_Save;
    QSpacerItem *verticalSpacer_4;
    QComboBox *comboBox_Gender;
    QLabel *label_Upload;
    QLabel *label_Name;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton_Cancel;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_Gender;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_AGE;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *lineEdit_UnameEdit;
    QLabel *label_Region;
    QSpacerItem *verticalSpacer_10;
    QPushButton *pushButton_Upload;

    void setupUi(QWidget *UserProFile)
    {
        if (UserProFile->objectName().isEmpty())
            UserProFile->setObjectName("UserProFile");
        UserProFile->resize(700, 600);
        UserProFile->setMinimumSize(QSize(700, 600));
        UserProFile->setMaximumSize(QSize(700, 600));
        gridLayout_2 = new QGridLayout(UserProFile);
        gridLayout_2->setObjectName("gridLayout_2");
        FirstWidget = new QWidget(UserProFile);
        FirstWidget->setObjectName("FirstWidget");
        verticalLayout_2 = new QVBoxLayout(FirstWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_ProFile = new QLabel(FirstWidget);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(200, 200));
        label_ProFile->setMaximumSize(QSize(200, 200));

        verticalLayout->addWidget(label_ProFile);

        label_DIsplayUname = new QLabel(FirstWidget);
        label_DIsplayUname->setObjectName("label_DIsplayUname");
        label_DIsplayUname->setMinimumSize(QSize(0, 30));
        label_DIsplayUname->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_DIsplayUname);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addWidget(FirstWidget, 0, 0, 1, 1);

        SecondWidget = new QWidget(UserProFile);
        SecondWidget->setObjectName("SecondWidget");
        gridLayout = new QGridLayout(SecondWidget);
        gridLayout->setObjectName("gridLayout");
        lineEdit_RegionEdit = new QLineEdit(SecondWidget);
        lineEdit_RegionEdit->setObjectName("lineEdit_RegionEdit");

        gridLayout->addWidget(lineEdit_RegionEdit, 11, 1, 1, 2);

        spinBox_Age = new QSpinBox(SecondWidget);
        spinBox_Age->setObjectName("spinBox_Age");

        gridLayout->addWidget(spinBox_Age, 9, 1, 1, 2);

        label_More = new QLabel(SecondWidget);
        label_More->setObjectName("label_More");

        gridLayout->addWidget(label_More, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 12, 0, 1, 1);

        pushButton_Save = new QPushButton(SecondWidget);
        pushButton_Save->setObjectName("pushButton_Save");

        gridLayout->addWidget(pushButton_Save, 13, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 0, 0, 1, 1);

        comboBox_Gender = new QComboBox(SecondWidget);
        comboBox_Gender->setObjectName("comboBox_Gender");

        gridLayout->addWidget(comboBox_Gender, 7, 1, 1, 2);

        label_Upload = new QLabel(SecondWidget);
        label_Upload->setObjectName("label_Upload");

        gridLayout->addWidget(label_Upload, 3, 0, 1, 1);

        label_Name = new QLabel(SecondWidget);
        label_Name->setObjectName("label_Name");

        gridLayout->addWidget(label_Name, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 14, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_7, 6, 0, 1, 1);

        pushButton_Cancel = new QPushButton(SecondWidget);
        pushButton_Cancel->setObjectName("pushButton_Cancel");

        gridLayout->addWidget(pushButton_Cancel, 13, 2, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_8, 8, 0, 1, 1);

        label_Gender = new QLabel(SecondWidget);
        label_Gender->setObjectName("label_Gender");

        gridLayout->addWidget(label_Gender, 7, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 2, 0, 1, 1);

        label_AGE = new QLabel(SecondWidget);
        label_AGE->setObjectName("label_AGE");

        gridLayout->addWidget(label_AGE, 9, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_9, 10, 0, 1, 1);

        lineEdit_UnameEdit = new QLineEdit(SecondWidget);
        lineEdit_UnameEdit->setObjectName("lineEdit_UnameEdit");

        gridLayout->addWidget(lineEdit_UnameEdit, 5, 1, 1, 2);

        label_Region = new QLabel(SecondWidget);
        label_Region->setObjectName("label_Region");

        gridLayout->addWidget(label_Region, 11, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_10, 4, 0, 1, 1);

        pushButton_Upload = new QPushButton(SecondWidget);
        pushButton_Upload->setObjectName("pushButton_Upload");

        gridLayout->addWidget(pushButton_Upload, 3, 1, 1, 2);


        gridLayout_2->addWidget(SecondWidget, 0, 1, 1, 1);

        QWidget::setTabOrder(pushButton_Save, pushButton_Cancel);
        QWidget::setTabOrder(pushButton_Cancel, comboBox_Gender);
        QWidget::setTabOrder(comboBox_Gender, spinBox_Age);
        QWidget::setTabOrder(spinBox_Age, lineEdit_RegionEdit);

        retranslateUi(UserProFile);

        QMetaObject::connectSlotsByName(UserProFile);
    } // setupUi

    void retranslateUi(QWidget *UserProFile)
    {
        UserProFile->setWindowTitle(QCoreApplication::translate("UserProFile", "\344\270\252\344\272\272\350\265\204\346\226\231", nullptr));
        label_ProFile->setText(QCoreApplication::translate("UserProFile", "TextLabel", nullptr));
        label_DIsplayUname->setText(QCoreApplication::translate("UserProFile", "\346\226\260\347\232\204\345\220\215\347\247\260", nullptr));
        lineEdit_RegionEdit->setPlaceholderText(QCoreApplication::translate("UserProFile", "\350\257\267\350\276\223\345\205\245\345\234\260\345\214\272", nullptr));
        label_More->setText(QCoreApplication::translate("UserProFile", "\346\233\264\345\244\232\344\277\241\346\201\257", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("UserProFile", "\344\277\235\345\255\230", nullptr));
        label_Upload->setText(QCoreApplication::translate("UserProFile", "\345\244\264\345\203\217", nullptr));
        label_Name->setText(QCoreApplication::translate("UserProFile", "\345\221\242\347\247\260", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("UserProFile", "\345\217\226\346\266\210", nullptr));
        label_Gender->setText(QCoreApplication::translate("UserProFile", "\346\200\247\345\210\253", nullptr));
        label_AGE->setText(QCoreApplication::translate("UserProFile", "\345\271\264\351\276\204", nullptr));
        lineEdit_UnameEdit->setPlaceholderText(QCoreApplication::translate("UserProFile", "\350\257\267\350\276\223\345\205\245\346\230\265\347\247\260", nullptr));
        label_Region->setText(QCoreApplication::translate("UserProFile", "\345\234\260\345\214\272", nullptr));
        pushButton_Upload->setText(QCoreApplication::translate("UserProFile", "\344\270\212\344\274\240\345\244\264\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserProFile: public Ui_UserProFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILE_H
