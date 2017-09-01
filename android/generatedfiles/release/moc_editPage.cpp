/****************************************************************************
** Meta object code from reading C++ file 'editPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/editPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_editPage_t {
    QByteArrayData data[14];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_editPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_editPage_t qt_meta_stringdata_editPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "editPage"
QT_MOC_LITERAL(1, 9, 18), // "dialogUpdateSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "updateSignal"
QT_MOC_LITERAL(4, 42, 17), // "timerUpdateSignal"
QT_MOC_LITERAL(5, 60, 12), // "valueChanged"
QT_MOC_LITERAL(6, 73, 5), // "value"
QT_MOC_LITERAL(7, 79, 4), // "hex1"
QT_MOC_LITERAL(8, 84, 4), // "hex2"
QT_MOC_LITERAL(9, 89, 4), // "hex3"
QT_MOC_LITERAL(10, 94, 12), // "updateDialog"
QT_MOC_LITERAL(11, 107, 5), // "index"
QT_MOC_LITERAL(12, 113, 13), // "updateDisplay"
QT_MOC_LITERAL(13, 127, 4) // "text"

    },
    "editPage\0dialogUpdateSignal\0\0updateSignal\0"
    "timerUpdateSignal\0valueChanged\0value\0"
    "hex1\0hex2\0hex3\0updateDialog\0index\0"
    "updateDisplay\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_editPage[] = {

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
       5,    4,   47,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      12,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void editPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        editPage *_t = static_cast<editPage *>(_o);
        switch (_id) {
        case 0: _t->dialogUpdateSignal(); break;
        case 1: _t->updateSignal(); break;
        case 2: _t->timerUpdateSignal(); break;
        case 3: _t->valueChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->updateDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (editPage::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&editPage::dialogUpdateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (editPage::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&editPage::updateSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (editPage::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&editPage::timerUpdateSignal)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject editPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_editPage.data,
      qt_meta_data_editPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *editPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *editPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_editPage.stringdata))
        return static_cast<void*>(const_cast< editPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int editPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void editPage::dialogUpdateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void editPage::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void editPage::timerUpdateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
