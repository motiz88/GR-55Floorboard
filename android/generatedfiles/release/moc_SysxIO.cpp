/****************************************************************************
** Meta object code from reading C++ file 'SysxIO.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/SysxIO.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SysxIO.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SysxIO_t {
    QByteArrayData data[31];
    char stringdata[376];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SysxIO_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SysxIO_t qt_meta_stringdata_SysxIO = {
    {
QT_MOC_LITERAL(0, 0, 6), // "SysxIO"
QT_MOC_LITERAL(1, 7, 9), // "sysxReply"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "sysxMsg"
QT_MOC_LITERAL(4, 26, 9), // "patchName"
QT_MOC_LITERAL(5, 36, 4), // "name"
QT_MOC_LITERAL(6, 41, 10), // "isFinished"
QT_MOC_LITERAL(7, 52, 9), // "isChanged"
QT_MOC_LITERAL(8, 62, 12), // "updateSignal"
QT_MOC_LITERAL(9, 75, 15), // "setStatusSymbol"
QT_MOC_LITERAL(10, 91, 5), // "value"
QT_MOC_LITERAL(11, 97, 17), // "setStatusProgress"
QT_MOC_LITERAL(12, 115, 16), // "setStatusMessage"
QT_MOC_LITERAL(13, 132, 7), // "message"
QT_MOC_LITERAL(14, 140, 20), // "setStatusdBugMessage"
QT_MOC_LITERAL(15, 161, 4), // "dBug"
QT_MOC_LITERAL(16, 166, 17), // "patchChangeFailed"
QT_MOC_LITERAL(17, 184, 18), // "notConnectedSignal"
QT_MOC_LITERAL(18, 203, 11), // "errorSignal"
QT_MOC_LITERAL(19, 215, 9), // "errorType"
QT_MOC_LITERAL(20, 225, 8), // "errorMsg"
QT_MOC_LITERAL(21, 234, 13), // "writeToBuffer"
QT_MOC_LITERAL(22, 248, 17), // "relayUpdateSignal"
QT_MOC_LITERAL(23, 266, 15), // "returnPatchName"
QT_MOC_LITERAL(24, 282, 11), // "receiveSysx"
QT_MOC_LITERAL(25, 294, 15), // "finishedSending"
QT_MOC_LITERAL(26, 310, 15), // "namePatchChange"
QT_MOC_LITERAL(27, 326, 11), // "resetDevice"
QT_MOC_LITERAL(28, 338, 16), // "checkPatchChange"
QT_MOC_LITERAL(29, 355, 11), // "systemReply"
QT_MOC_LITERAL(30, 367, 8) // "replyMsg"

    },
    "SysxIO\0sysxReply\0\0sysxMsg\0patchName\0"
    "name\0isFinished\0isChanged\0updateSignal\0"
    "setStatusSymbol\0value\0setStatusProgress\0"
    "setStatusMessage\0message\0setStatusdBugMessage\0"
    "dBug\0patchChangeFailed\0notConnectedSignal\0"
    "errorSignal\0errorType\0errorMsg\0"
    "writeToBuffer\0relayUpdateSignal\0"
    "returnPatchName\0receiveSysx\0finishedSending\0"
    "namePatchChange\0resetDevice\0"
    "checkPatchChange\0systemReply\0replyMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysxIO[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    1,  122,    2, 0x06 /* Public */,
       6,    0,  125,    2, 0x06 /* Public */,
       7,    0,  126,    2, 0x06 /* Public */,
       8,    0,  127,    2, 0x06 /* Public */,
       9,    1,  128,    2, 0x06 /* Public */,
      11,    1,  131,    2, 0x06 /* Public */,
      12,    1,  134,    2, 0x06 /* Public */,
      14,    1,  137,    2, 0x06 /* Public */,
      16,    0,  140,    2, 0x06 /* Public */,
      17,    0,  141,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    2,  142,    2, 0x0a /* Public */,
      21,    0,  147,    2, 0x0a /* Public */,
      22,    0,  148,    2, 0x0a /* Public */,
      23,    1,  149,    2, 0x08 /* Private */,
      24,    1,  152,    2, 0x08 /* Private */,
      25,    0,  155,    2, 0x08 /* Private */,
      26,    0,  156,    2, 0x08 /* Private */,
      27,    1,  157,    2, 0x08 /* Private */,
      28,    1,  160,    2, 0x08 /* Private */,
      29,    1,  163,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   30,

       0        // eod
};

void SysxIO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SysxIO *_t = static_cast<SysxIO *>(_o);
        switch (_id) {
        case 0: _t->sysxReply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->patchName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->isFinished(); break;
        case 3: _t->isChanged(); break;
        case 4: _t->updateSignal(); break;
        case 5: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setStatusdBugMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->patchChangeFailed(); break;
        case 10: _t->notConnectedSignal(); break;
        case 11: _t->errorSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->writeToBuffer(); break;
        case 13: _t->relayUpdateSignal(); break;
        case 14: _t->returnPatchName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->receiveSysx((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->finishedSending(); break;
        case 17: _t->namePatchChange(); break;
        case 18: _t->resetDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->checkPatchChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->systemReply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SysxIO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::sysxReply)) {
                *result = 0;
            }
        }
        {
            typedef void (SysxIO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::patchName)) {
                *result = 1;
            }
        }
        {
            typedef void (SysxIO::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::isFinished)) {
                *result = 2;
            }
        }
        {
            typedef void (SysxIO::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::isChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (SysxIO::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::updateSignal)) {
                *result = 4;
            }
        }
        {
            typedef void (SysxIO::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::setStatusSymbol)) {
                *result = 5;
            }
        }
        {
            typedef void (SysxIO::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::setStatusProgress)) {
                *result = 6;
            }
        }
        {
            typedef void (SysxIO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::setStatusMessage)) {
                *result = 7;
            }
        }
        {
            typedef void (SysxIO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::setStatusdBugMessage)) {
                *result = 8;
            }
        }
        {
            typedef void (SysxIO::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::patchChangeFailed)) {
                *result = 9;
            }
        }
        {
            typedef void (SysxIO::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SysxIO::notConnectedSignal)) {
                *result = 10;
            }
        }
    }
}

const QMetaObject SysxIO::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SysxIO.data,
      qt_meta_data_SysxIO,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SysxIO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SysxIO::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SysxIO.stringdata))
        return static_cast<void*>(const_cast< SysxIO*>(this));
    return QObject::qt_metacast(_clname);
}

int SysxIO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void SysxIO::sysxReply(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SysxIO::patchName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SysxIO::isFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SysxIO::isChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void SysxIO::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void SysxIO::setStatusSymbol(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SysxIO::setStatusProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SysxIO::setStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SysxIO::setStatusdBugMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SysxIO::patchChangeFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void SysxIO::notConnectedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
