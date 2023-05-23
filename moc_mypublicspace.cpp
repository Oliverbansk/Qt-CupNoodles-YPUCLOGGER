/****************************************************************************
** Meta object code from reading C++ file 'mypublicspace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mypublicspace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypublicspace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyPublicSpace_t {
    QByteArrayData data[20];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyPublicSpace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyPublicSpace_t qt_meta_stringdata_MyPublicSpace = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MyPublicSpace"
QT_MOC_LITERAL(1, 14, 9), // "showLogin"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "showHomepage"
QT_MOC_LITERAL(4, 38, 20), // "showMoviesCollection"
QT_MOC_LITERAL(5, 59, 15), // "showMovieDetail"
QT_MOC_LITERAL(6, 75, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(7, 99, 25), // "on_homepageButton_clicked"
QT_MOC_LITERAL(8, 125, 17), // "receiveLoginInput"
QT_MOC_LITERAL(9, 143, 15), // "receiveHomepage"
QT_MOC_LITERAL(10, 159, 23), // "receiveMoviesCollection"
QT_MOC_LITERAL(11, 183, 19), // "receiveVisitorLogin"
QT_MOC_LITERAL(12, 203, 18), // "receiveMovieDetail"
QT_MOC_LITERAL(13, 222, 33), // "on_moviesCollectionButton_cli..."
QT_MOC_LITERAL(14, 256, 26), // "on_detailButton_r1_clicked"
QT_MOC_LITERAL(15, 283, 26), // "on_detailButton_r2_clicked"
QT_MOC_LITERAL(16, 310, 26), // "on_detailButton_r3_clicked"
QT_MOC_LITERAL(17, 337, 26), // "on_detailButton_f1_clicked"
QT_MOC_LITERAL(18, 364, 26), // "on_detailButton_f2_clicked"
QT_MOC_LITERAL(19, 391, 26) // "on_detailButton_f3_clicked"

    },
    "MyPublicSpace\0showLogin\0\0showHomepage\0"
    "showMoviesCollection\0showMovieDetail\0"
    "on_returnButton_clicked\0"
    "on_homepageButton_clicked\0receiveLoginInput\0"
    "receiveHomepage\0receiveMoviesCollection\0"
    "receiveVisitorLogin\0receiveMovieDetail\0"
    "on_moviesCollectionButton_clicked\0"
    "on_detailButton_r1_clicked\0"
    "on_detailButton_r2_clicked\0"
    "on_detailButton_r3_clicked\0"
    "on_detailButton_f1_clicked\0"
    "on_detailButton_f2_clicked\0"
    "on_detailButton_f3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPublicSpace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyPublicSpace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPublicSpace *_t = static_cast<MyPublicSpace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLogin(); break;
        case 1: _t->showHomepage(); break;
        case 2: _t->showMoviesCollection(); break;
        case 3: _t->showMovieDetail(); break;
        case 4: _t->on_returnButton_clicked(); break;
        case 5: _t->on_homepageButton_clicked(); break;
        case 6: _t->receiveLoginInput(); break;
        case 7: _t->receiveHomepage(); break;
        case 8: _t->receiveMoviesCollection(); break;
        case 9: _t->receiveVisitorLogin(); break;
        case 10: _t->receiveMovieDetail(); break;
        case 11: _t->on_moviesCollectionButton_clicked(); break;
        case 12: _t->on_detailButton_r1_clicked(); break;
        case 13: _t->on_detailButton_r2_clicked(); break;
        case 14: _t->on_detailButton_r3_clicked(); break;
        case 15: _t->on_detailButton_f1_clicked(); break;
        case 16: _t->on_detailButton_f2_clicked(); break;
        case 17: _t->on_detailButton_f3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MyPublicSpace::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPublicSpace::showLogin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyPublicSpace::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPublicSpace::showHomepage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyPublicSpace::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPublicSpace::showMoviesCollection)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyPublicSpace::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyPublicSpace::showMovieDetail)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyPublicSpace::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyPublicSpace.data,
      qt_meta_data_MyPublicSpace,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyPublicSpace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPublicSpace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyPublicSpace.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyPublicSpace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MyPublicSpace::showLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyPublicSpace::showHomepage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyPublicSpace::showMoviesCollection()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyPublicSpace::showMovieDetail()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
