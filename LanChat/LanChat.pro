QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = logo_3.ico

SOURCES += \
    addfriend.cpp \
    addverification.cpp \
    chatmessagedelegate.cpp \
    friendsdetails.cpp \
    friendsitemdelegate.cpp \
    friendsrequest.cpp \
    friendsrequestitemdelegate.cpp \
    login.cpp \
    main.cpp \
    mainwidget.cpp \
    messageitemdelegate.cpp \
    nonclickablechatmodel.cpp \
    signup.cpp \
    userprofile.cpp

HEADERS += \
    addfriend.h \
    addverification.h \
    chatmessagedelegate.h \
    friendsdetails.h \
    friendsitemdelegate.h \
    friendsrequest.h \
    friendsrequestitemdelegate.h \
    login.h \
    mainwidget.h \
    messageitemdelegate.h \
    nonclickablechatmodel.h \
    signup.h \
    userprofile.h

FORMS += \
    addfriend.ui \
    addverification.ui \
    login.ui \
    mainwidget.ui \
    signup.ui \
    userprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES +=
