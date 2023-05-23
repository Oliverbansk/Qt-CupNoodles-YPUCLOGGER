/****************************************************************************
** Meta object code from reading C++ file 'myadminlogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myadminlogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myadminlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyAdminLoginInput_t {
    QByteArrayData data[8];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyAdminLoginInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyAdminLoginInput_t qt_meta_stringdata_MyAdminLoginInput = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MyAdminLoginInput"
QT_MOC_LITERAL(1, 18, 9), // "showLogin"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "showAdminEdit"
QT_MOC_LITERAL(4, 43, 9), // "showAgain"
QT_MOC_LITERAL(5, 53, 12), // "receiveLogin"
QT_MOC_LITERAL(6, 66, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(7, 90, 21) // "on_pushButton_clicked"

    },
    "MyAdminLoginInput\0showLogin\0\0showAdminEdit\0"
    "showAgain\0receiveLogin\0on_returnButton_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyAdminLoginInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyAdminLoginInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyAdminLoginInput *_t = static_cast<MyAdminLoginInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLogin(); break;
        case 1: _t->showAdminEdit(); break;
        case 2: _t->showAgain(); break;
        case 3: _t->receiveLogin(); break;
        case 4: _t->on_returnButton_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MyAdminLoginInput::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyAdminLoginInput::showLogin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyAdminLoginInput::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyAdminLoginInput::showAdminEdit)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyAdminLoginInput::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyAdminLoginInput::showAgain)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyAdminLoginInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyAdminLoginInput.data,
      qt_meta_data_MyAdminLoginInput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyAdminLoginInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyAdminLoginInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyAdminLoginInput.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyAdminLoginInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MyAdminLoginInput::showLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyAdminLoginInput::showAdminEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyAdminLoginInput::showAgain()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
