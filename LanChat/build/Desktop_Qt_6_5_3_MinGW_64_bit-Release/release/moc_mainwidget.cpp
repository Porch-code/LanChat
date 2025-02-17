/****************************************************************************
** Meta object code from reading C++ file 'mainwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWidgetENDCLASS = QtMocHelpers::stringData(
    "MainWidget",
    "chatSessionIdReady",
    "",
    "on_pushButton_FontColor_clicked",
    "on_pushButton_Bold_clicked",
    "checked",
    "on_pushButton_Italic_clicked",
    "on_pushButton_UnderLine_clicked",
    "on_pushButton_Message_released",
    "on_pushButton_Friend_released",
    "on_pushButton_Setting_released",
    "onAvatarLoaded",
    "pixmap",
    "on_pushButton_AddFriend_released",
    "updateAvatar",
    "avatarBase64",
    "onStatusChanged",
    "newStatus",
    "onSocketReadyRead",
    "onSocketConnected",
    "onSocketError",
    "QAbstractSocket::SocketError",
    "error",
    "on_pushButton_SendMsg_released"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWidgetENDCLASS_t {
    uint offsetsAndSizes[48];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[27];
    char stringdata5[8];
    char stringdata6[29];
    char stringdata7[32];
    char stringdata8[31];
    char stringdata9[30];
    char stringdata10[31];
    char stringdata11[15];
    char stringdata12[7];
    char stringdata13[33];
    char stringdata14[13];
    char stringdata15[13];
    char stringdata16[16];
    char stringdata17[10];
    char stringdata18[18];
    char stringdata19[18];
    char stringdata20[14];
    char stringdata21[29];
    char stringdata22[6];
    char stringdata23[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWidgetENDCLASS_t qt_meta_stringdata_CLASSMainWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWidget"
        QT_MOC_LITERAL(11, 18),  // "chatSessionIdReady"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 31),  // "on_pushButton_FontColor_clicked"
        QT_MOC_LITERAL(63, 26),  // "on_pushButton_Bold_clicked"
        QT_MOC_LITERAL(90, 7),  // "checked"
        QT_MOC_LITERAL(98, 28),  // "on_pushButton_Italic_clicked"
        QT_MOC_LITERAL(127, 31),  // "on_pushButton_UnderLine_clicked"
        QT_MOC_LITERAL(159, 30),  // "on_pushButton_Message_released"
        QT_MOC_LITERAL(190, 29),  // "on_pushButton_Friend_released"
        QT_MOC_LITERAL(220, 30),  // "on_pushButton_Setting_released"
        QT_MOC_LITERAL(251, 14),  // "onAvatarLoaded"
        QT_MOC_LITERAL(266, 6),  // "pixmap"
        QT_MOC_LITERAL(273, 32),  // "on_pushButton_AddFriend_released"
        QT_MOC_LITERAL(306, 12),  // "updateAvatar"
        QT_MOC_LITERAL(319, 12),  // "avatarBase64"
        QT_MOC_LITERAL(332, 15),  // "onStatusChanged"
        QT_MOC_LITERAL(348, 9),  // "newStatus"
        QT_MOC_LITERAL(358, 17),  // "onSocketReadyRead"
        QT_MOC_LITERAL(376, 17),  // "onSocketConnected"
        QT_MOC_LITERAL(394, 13),  // "onSocketError"
        QT_MOC_LITERAL(408, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(437, 5),  // "error"
        QT_MOC_LITERAL(443, 30)   // "on_pushButton_SendMsg_released"
    },
    "MainWidget",
    "chatSessionIdReady",
    "",
    "on_pushButton_FontColor_clicked",
    "on_pushButton_Bold_clicked",
    "checked",
    "on_pushButton_Italic_clicked",
    "on_pushButton_UnderLine_clicked",
    "on_pushButton_Message_released",
    "on_pushButton_Friend_released",
    "on_pushButton_Setting_released",
    "onAvatarLoaded",
    "pixmap",
    "on_pushButton_AddFriend_released",
    "updateAvatar",
    "avatarBase64",
    "onStatusChanged",
    "newStatus",
    "onSocketReadyRead",
    "onSocketConnected",
    "onSocketError",
    "QAbstractSocket::SocketError",
    "error",
    "on_pushButton_SendMsg_released"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  111,    2, 0x08,    2 /* Private */,
       4,    1,  112,    2, 0x08,    3 /* Private */,
       6,    1,  115,    2, 0x08,    5 /* Private */,
       7,    1,  118,    2, 0x08,    7 /* Private */,
       8,    0,  121,    2, 0x08,    9 /* Private */,
       9,    0,  122,    2, 0x08,   10 /* Private */,
      10,    0,  123,    2, 0x08,   11 /* Private */,
      11,    1,  124,    2, 0x08,   12 /* Private */,
      13,    0,  127,    2, 0x08,   14 /* Private */,
      14,    1,  128,    2, 0x08,   15 /* Private */,
      16,    1,  131,    2, 0x08,   17 /* Private */,
      18,    0,  134,    2, 0x08,   19 /* Private */,
      19,    0,  135,    2, 0x08,   20 /* Private */,
      20,    1,  136,    2, 0x08,   21 /* Private */,
      23,    0,  139,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWidget, std::true_type>,
        // method 'chatSessionIdReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_FontColor_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Bold_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_Italic_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_UnderLine_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_Message_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Friend_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Setting_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAvatarLoaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPixmap &, std::false_type>,
        // method 'on_pushButton_AddFriend_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateAvatar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'onSocketReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSocketConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSocketError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'on_pushButton_SendMsg_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->chatSessionIdReady(); break;
        case 1: _t->on_pushButton_FontColor_clicked(); break;
        case 2: _t->on_pushButton_Bold_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_pushButton_Italic_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_pushButton_UnderLine_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_pushButton_Message_released(); break;
        case 6: _t->on_pushButton_Friend_released(); break;
        case 7: _t->on_pushButton_Setting_released(); break;
        case 8: _t->onAvatarLoaded((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 9: _t->on_pushButton_AddFriend_released(); break;
        case 10: _t->updateAvatar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->onStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->onSocketReadyRead(); break;
        case 13: _t->onSocketConnected(); break;
        case 14: _t->onSocketError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 15: _t->on_pushButton_SendMsg_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWidget::*)();
            if (_t _q_method = &MainWidget::chatSessionIdReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWidget::chatSessionIdReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
