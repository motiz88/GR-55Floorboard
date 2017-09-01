/****************************************************************************
** Meta object code from reading C++ file 'bulkEditDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/bulkEditDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bulkEditDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_bulkEditDialog_t {
    QByteArrayData data[16];
    char stringdata[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bulkEditDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bulkEditDialog_t qt_meta_stringdata_bulkEditDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "bulkEditDialog"
QT_MOC_LITERAL(1, 15, 16), // "setStatusMessage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "message"
QT_MOC_LITERAL(4, 41, 17), // "setStatusProgress"
QT_MOC_LITERAL(5, 59, 5), // "value"
QT_MOC_LITERAL(6, 65, 15), // "setStatusSymbol"
QT_MOC_LITERAL(7, 81, 21), // "setdeBugStatusMessage"
QT_MOC_LITERAL(8, 103, 8), // "sendData"
QT_MOC_LITERAL(9, 112, 11), // "prepareData"
QT_MOC_LITERAL(10, 124, 18), // "bulkStatusProgress"
QT_MOC_LITERAL(11, 143, 12), // "sendSequence"
QT_MOC_LITERAL(12, 156, 9), // "sendPatch"
QT_MOC_LITERAL(13, 166, 4), // "data"
QT_MOC_LITERAL(14, 171, 17), // "comboValueChanged"
QT_MOC_LITERAL(15, 189, 5) // "close"

    },
    "bulkEditDialog\0setStatusMessage\0\0"
    "message\0setStatusProgress\0value\0"
    "setStatusSymbol\0setdeBugStatusMessage\0"
    "sendData\0prepareData\0bulkStatusProgress\0"
    "sendSequence\0sendPatch\0data\0"
    "comboValueChanged\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bulkEditDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       7,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    1,   83,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,
      14,    1,   92,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void bulkEditDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bulkEditDialog *_t = static_cast<bulkEditDialog *>(_o);
        switch (_id) {
        case 0: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setdeBugStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sendData(); break;
        case 5: _t->prepareData(); break;
        case 6: _t->bulkStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sendSequence((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sendPatch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->comboValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bulkEditDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkEditDialog::setStatusMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (bulkEditDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkEditDialog::setStatusProgress)) {
                *result = 1;
            }
        }
        {
            typedef void (bulkEditDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkEditDialog::setStatusSymbol)) {
                *result = 2;
            }
        }
        {
            typedef void (bulkEditDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkEditDialog::setdeBugStatusMessage)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject bulkEditDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_bulkEditDialog.data,
      qt_meta_data_bulkEditDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bulkEditDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bulkEditDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bulkEditDialog.stringdata))
        return static_cast<void*>(const_cast< bulkEditDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int bulkEditDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void bulkEditDialog::setStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void bulkEditDialog::setStatusProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void bulkEditDialog::setStatusSymbol(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void bulkEditDialog::setdeBugStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
