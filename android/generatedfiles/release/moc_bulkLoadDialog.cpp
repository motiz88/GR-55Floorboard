/****************************************************************************
** Meta object code from reading C++ file 'bulkLoadDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/bulkLoadDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bulkLoadDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_bulkLoadDialog_t {
    QByteArrayData data[17];
    char stringdata[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bulkLoadDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bulkLoadDialog_t qt_meta_stringdata_bulkLoadDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "bulkLoadDialog"
QT_MOC_LITERAL(1, 15, 16), // "setStatusMessage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "message"
QT_MOC_LITERAL(4, 41, 17), // "setStatusProgress"
QT_MOC_LITERAL(5, 59, 5), // "value"
QT_MOC_LITERAL(6, 65, 15), // "setStatusSymbol"
QT_MOC_LITERAL(7, 81, 21), // "setdeBugStatusMessage"
QT_MOC_LITERAL(8, 103, 7), // "started"
QT_MOC_LITERAL(9, 111, 8), // "sendData"
QT_MOC_LITERAL(10, 120, 17), // "comboValueChanged"
QT_MOC_LITERAL(11, 138, 11), // "DialogClose"
QT_MOC_LITERAL(12, 150, 11), // "updatePatch"
QT_MOC_LITERAL(13, 162, 18), // "bulkStatusProgress"
QT_MOC_LITERAL(14, 181, 12), // "sendSequence"
QT_MOC_LITERAL(15, 194, 9), // "sendPatch"
QT_MOC_LITERAL(16, 204, 4) // "data"

    },
    "bulkLoadDialog\0setStatusMessage\0\0"
    "message\0setStatusProgress\0value\0"
    "setStatusSymbol\0setdeBugStatusMessage\0"
    "started\0sendData\0comboValueChanged\0"
    "DialogClose\0updatePatch\0bulkStatusProgress\0"
    "sendSequence\0sendPatch\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bulkLoadDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,
       8,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   87,    2, 0x0a /* Public */,
      10,    1,   88,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void bulkLoadDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bulkLoadDialog *_t = static_cast<bulkLoadDialog *>(_o);
        switch (_id) {
        case 0: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setdeBugStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->started(); break;
        case 5: _t->sendData(); break;
        case 6: _t->comboValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->DialogClose(); break;
        case 8: _t->updatePatch(); break;
        case 9: _t->bulkStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->sendSequence(); break;
        case 11: _t->sendPatch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (bulkLoadDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkLoadDialog::setStatusMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (bulkLoadDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkLoadDialog::setStatusProgress)) {
                *result = 1;
            }
        }
        {
            typedef void (bulkLoadDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkLoadDialog::setStatusSymbol)) {
                *result = 2;
            }
        }
        {
            typedef void (bulkLoadDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkLoadDialog::setdeBugStatusMessage)) {
                *result = 3;
            }
        }
        {
            typedef void (bulkLoadDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&bulkLoadDialog::started)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject bulkLoadDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_bulkLoadDialog.data,
      qt_meta_data_bulkLoadDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *bulkLoadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bulkLoadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_bulkLoadDialog.stringdata))
        return static_cast<void*>(const_cast< bulkLoadDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int bulkLoadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void bulkLoadDialog::setStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void bulkLoadDialog::setStatusProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void bulkLoadDialog::setStatusSymbol(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void bulkLoadDialog::setdeBugStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void bulkLoadDialog::started()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
