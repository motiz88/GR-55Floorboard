/****************************************************************************
** Meta object code from reading C++ file 'bulkSaveDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/bulkSaveDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bulkSaveDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_bulkSaveDialog_t {
    QByteArrayData data[16];
    char stringdata[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bulkSaveDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bulkSaveDialog_t qt_meta_stringdata_bulkSaveDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "bulkSaveDialog"
QT_MOC_LITERAL(1, 15, 16), // "setStatusMessage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "message"
QT_MOC_LITERAL(4, 41, 17), // "setStatusProgress"
QT_MOC_LITERAL(5, 59, 5), // "value"
QT_MOC_LITERAL(6, 65, 15), // "setStatusSymbol"
QT_MOC_LITERAL(7, 81, 12), // "comboChanged"
QT_MOC_LITERAL(8, 94, 6), // "backup"
QT_MOC_LITERAL(9, 101, 12), // "requestPatch"
QT_MOC_LITERAL(10, 114, 4), // "bank"
QT_MOC_LITERAL(11, 119, 5), // "patch"
QT_MOC_LITERAL(12, 125, 11), // "updatePatch"
QT_MOC_LITERAL(13, 137, 8), // "replyMsg"
QT_MOC_LITERAL(14, 146, 18), // "bulkStatusProgress"
QT_MOC_LITERAL(15, 165, 11) // "DialogClose"

    },
    "bulkSaveDialog\0setStatusMessage\0\0"
    "message\0setStatusProgress\0value\0"
    "setStatusSymbol\0comboChanged\0backup\0"
    "requestPatch\0bank\0patch\0updatePatch\0"
    "replyMsg\0bulkStatusProgress\0DialogClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bulkSaveDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   68,    2, 0x0a /* Public */,
       8,    0,   69,    2, 0x0a /* Public */,
       9,    2,   70,    2, 0x0a /* Public */,
      12,    1,   75,    2, 0x0a /* Public */,
      14,    1,   78,    2, 0x0a /* Public */,
      15,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void bulkSaveDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bulkSaveDialog *_t = static_cast<bulkSaveDialog *>(_o);
        switch (_id) {
        case 0: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->comboChanged(); break;
        case 4: _t->backup(); break;
        case 5: _t->requestPatch((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updatePatch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->bulkStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->DialogClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bulkSaveDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkSaveDialog::setStatusMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (bulkSaveDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkSaveDialog::setStatusProgress)) {
                *result = 1;
            }
        }
        {
            typedef void (bulkSaveDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkSaveDialog::setStatusSymbol)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject bulkSaveDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_bulkSaveDialog.data,
      qt_meta_data_bulkSaveDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bulkSaveDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bulkSaveDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bulkSaveDialog.stringdata))
        return static_cast<void*>(const_cast< bulkSaveDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int bulkSaveDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void bulkSaveDialog::setStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void bulkSaveDialog::setStatusProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void bulkSaveDialog::setStatusSymbol(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
