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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserProFile
{
public:
    QGridLayout *gridLayout_2;
    QWidget *FirstWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_ProFile;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Save;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *SecondWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_Name;
    QLineEdit *lineEdit_UnameEdit;
    QLabel *label_Gender;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_Upload;
    QPushButton *pushButton_Upload;
    QLabel *label_More;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_10;
    QComboBox *comboBox_Gender;
    QLabel *label_Region;
    QLabel *label_AGE;
    QLineEdit *lineEdit_RegionEdit;
    QSpinBox *spinBox_Age;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

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
        FirstWidget->setMinimumSize(QSize(280, 0));
        FirstWidget->setMaximumSize(QSize(280, 16777215));
        gridLayout_4 = new QGridLayout(FirstWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(0);
        gridLayout_4->setVerticalSpacing(3);
        gridLayout_4->setContentsMargins(9, -1, -1, -1);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(0);
        label_ProFile = new QLabel(FirstWidget);
        label_ProFile->setObjectName("label_ProFile");
        label_ProFile->setMinimumSize(QSize(200, 200));
        label_ProFile->setMaximumSize(QSize(200, 200));

        gridLayout_3->addWidget(label_ProFile, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 3);

        pushButton_Cancel = new QPushButton(FirstWidget);
        pushButton_Cancel->setObjectName("pushButton_Cancel");
        pushButton_Cancel->setMinimumSize(QSize(120, 30));
        pushButton_Cancel->setMaximumSize(QSize(120, 16777215));

        gridLayout_4->addWidget(pushButton_Cancel, 3, 2, 1, 1);

        pushButton_Save = new QPushButton(FirstWidget);
        pushButton_Save->setObjectName("pushButton_Save");
        pushButton_Save->setMinimumSize(QSize(120, 30));
        pushButton_Save->setMaximumSize(QSize(120, 16777215));

        gridLayout_4->addWidget(pushButton_Save, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(5, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_3, 4, 1, 1, 1);


        gridLayout_2->addWidget(FirstWidget, 0, 0, 1, 1);

        SecondWidget = new QWidget(UserProFile);
        SecondWidget->setObjectName("SecondWidget");
        gridLayout = new QGridLayout(SecondWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 1, 0, 1, 1);

        label_Name = new QLabel(SecondWidget);
        label_Name->setObjectName("label_Name");
        QFont font;
        font.setPointSize(10);
        label_Name->setFont(font);

        gridLayout->addWidget(label_Name, 4, 0, 1, 1);

        lineEdit_UnameEdit = new QLineEdit(SecondWidget);
        lineEdit_UnameEdit->setObjectName("lineEdit_UnameEdit");
        lineEdit_UnameEdit->setFont(font);
        lineEdit_UnameEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_UnameEdit, 4, 1, 1, 2);

        label_Gender = new QLabel(SecondWidget);
        label_Gender->setObjectName("label_Gender");
        label_Gender->setFont(font);

        gridLayout->addWidget(label_Gender, 6, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_7, 5, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_9, 9, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_8, 7, 0, 1, 1);

        label_Upload = new QLabel(SecondWidget);
        label_Upload->setObjectName("label_Upload");
        label_Upload->setFont(font);

        gridLayout->addWidget(label_Upload, 2, 0, 1, 1);

        pushButton_Upload = new QPushButton(SecondWidget);
        pushButton_Upload->setObjectName("pushButton_Upload");
        pushButton_Upload->setMinimumSize(QSize(0, 30));
        pushButton_Upload->setMaximumSize(QSize(16777215, 30));
        pushButton_Upload->setFont(font);

        gridLayout->addWidget(pushButton_Upload, 2, 1, 1, 2);

        label_More = new QLabel(SecondWidget);
        label_More->setObjectName("label_More");
        label_More->setFont(font);

        gridLayout->addWidget(label_More, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 280, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 11, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_10, 3, 0, 1, 1);

        comboBox_Gender = new QComboBox(SecondWidget);
        comboBox_Gender->setObjectName("comboBox_Gender");
        comboBox_Gender->setFont(font);

        gridLayout->addWidget(comboBox_Gender, 6, 1, 1, 2);

        label_Region = new QLabel(SecondWidget);
        label_Region->setObjectName("label_Region");
        label_Region->setFont(font);

        gridLayout->addWidget(label_Region, 10, 0, 1, 1);

        label_AGE = new QLabel(SecondWidget);
        label_AGE->setObjectName("label_AGE");
        label_AGE->setFont(font);

        gridLayout->addWidget(label_AGE, 8, 0, 1, 1);

        lineEdit_RegionEdit = new QLineEdit(SecondWidget);
        lineEdit_RegionEdit->setObjectName("lineEdit_RegionEdit");
        lineEdit_RegionEdit->setFont(font);
        lineEdit_RegionEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_RegionEdit, 10, 1, 1, 2);

        spinBox_Age = new QSpinBox(SecondWidget);
        spinBox_Age->setObjectName("spinBox_Age");
        spinBox_Age->setFont(font);
        spinBox_Age->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(spinBox_Age, 8, 1, 1, 2);


        gridLayout_2->addWidget(SecondWidget, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        QWidget::setTabOrder(comboBox_Gender, spinBox_Age);
        QWidget::setTabOrder(spinBox_Age, lineEdit_RegionEdit);

        retranslateUi(UserProFile);

        QMetaObject::connectSlotsByName(UserProFile);
    } // setupUi

    void retranslateUi(QWidget *UserProFile)
    {
        UserProFile->setWindowTitle(QCoreApplication::translate("UserProFile", "\344\270\252\344\272\272\350\265\204\346\226\231", nullptr));
        label_ProFile->setText(QCoreApplication::translate("UserProFile", "TextLabel", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("UserProFile", "\345\217\226\346\266\210", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("UserProFile", "\344\277\235\345\255\230", nullptr));
        label_Name->setText(QCoreApplication::translate("UserProFile", "\345\221\242\347\247\260", nullptr));
        lineEdit_UnameEdit->setPlaceholderText(QCoreApplication::translate("UserProFile", "\350\257\267\350\276\223\345\205\245\346\230\265\347\247\260", nullptr));
        label_Gender->setText(QCoreApplication::translate("UserProFile", "\346\200\247\345\210\253", nullptr));
        label_Upload->setText(QCoreApplication::translate("UserProFile", "\345\244\264\345\203\217", nullptr));
        pushButton_Upload->setText(QCoreApplication::translate("UserProFile", "\344\270\212\344\274\240\345\244\264\345\203\217", nullptr));
        label_More->setText(QCoreApplication::translate("UserProFile", "\346\233\264\345\244\232\344\277\241\346\201\257", nullptr));
        label_Region->setText(QCoreApplication::translate("UserProFile", "\345\234\260\345\214\272", nullptr));
        label_AGE->setText(QCoreApplication::translate("UserProFile", "\345\271\264\351\276\204", nullptr));
        lineEdit_RegionEdit->setPlaceholderText(QCoreApplication::translate("UserProFile", "\350\257\267\350\276\223\345\205\245\345\234\260\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserProFile: public Ui_UserProFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILE_H
