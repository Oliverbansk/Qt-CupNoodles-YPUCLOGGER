/****************************************************************************
** Meta object code from reading C++ file 'mylogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mylogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mylogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLogin_t {
    QByteArrayData data[12];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLogin_t qt_meta_stringdata_MyLogin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyLogin"
QT_MOC_LITERAL(1, 8, 14), // "showLoginInput"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 19), // "showAdminLoginInput"
QT_MOC_LITERAL(4, 44, 22), // "showVisitorPublicSpace"
QT_MOC_LITERAL(5, 67, 17), // "receiveLoginInput"
QT_MOC_LITERAL(6, 85, 17), // "on_btUser_clicked"
QT_MOC_LITERAL(7, 103, 18), // "on_btAdmin_clicked"
QT_MOC_LITERAL(8, 122, 17), // "receiveAdminInput"
QT_MOC_LITERAL(9, 140, 16), // "receiveAdminEdit"
QT_MOC_LITERAL(10, 157, 13), // "receiveOthers"
QT_MOC_LITERAL(11, 171, 20) // "on_btVisitor_clicked"

    },
    "MyLogin\0showLoginInput\0\0showAdminLoginInput\0"
    "showVisitorPublicSpace\0receiveLoginInput\0"
    "on_btUser_clicked\0on_btAdmin_clicked\0"
    "receiveAdminInput\0receiveAdminEdit\0"
    "receiveOthers\0on_btVisitor_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLogin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLogin *_t = static_cast<MyLogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLoginInput(); break;
        case 1: _t->showAdminLoginInput(); break;
        case 2: _t->showVisitorPublicSpace(); break;
        case 3: _t->receiveLoginInput(); break;
        case 4: _t->on_btUser_clicked(); break;
        case 5: _t->on_btAdmin_clicked(); break;
        case 6: _t->receiveAdminInput(); break;
        case 7: _t->receiveAdminEdit(); break;
        case 8: _t->receiveOthers(); break;
        case 9: _t->on_btVisitor_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MyLogin::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLogin::showLoginInput)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyLogin::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLogin::showAdminLoginInput)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyLogin::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLogin::showVisitorPublicSpace)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyLogin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyLogin.data,
      qt_meta_data_MyLogin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLogin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MyLogin::showLoginInput()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyLogin::showAdminLoginInput()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyLogin::showVisitorPublicSpace()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
