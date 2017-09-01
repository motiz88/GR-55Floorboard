/****************************************************************************
** Meta object code from reading C++ file 'midiIO.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/midiIO.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'midiIO.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_midiIO_t {
    QByteArrayData data[16];
    char stringdata[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_midiIO_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_midiIO_t qt_meta_stringdata_midiIO = {
    {
QT_MOC_LITERAL(0, 0, 6), // "midiIO"
QT_MOC_LITERAL(1, 7, 11), // "errorSignal"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "windowTitle"
QT_MOC_LITERAL(4, 32, 8), // "errorMsg"
QT_MOC_LITERAL(5, 41, 8), // "replyMsg"
QT_MOC_LITERAL(6, 50, 9), // "sysxInMsg"
QT_MOC_LITERAL(7, 60, 12), // "midiFinished"
QT_MOC_LITERAL(8, 73, 7), // "started"
QT_MOC_LITERAL(9, 81, 15), // "setStatusSymbol"
QT_MOC_LITERAL(10, 97, 5), // "value"
QT_MOC_LITERAL(11, 103, 17), // "setStatusProgress"
QT_MOC_LITERAL(12, 121, 16), // "setStatusMessage"
QT_MOC_LITERAL(13, 138, 7), // "message"
QT_MOC_LITERAL(14, 146, 20), // "setStatusdBugMessage"
QT_MOC_LITERAL(15, 167, 4) // "dBug"

    },
    "midiIO\0errorSignal\0\0windowTitle\0"
    "errorMsg\0replyMsg\0sysxInMsg\0midiFinished\0"
    "started\0setStatusSymbol\0value\0"
    "setStatusProgress\0setStatusMessage\0"
    "message\0setStatusdBugMessage\0dBug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_midiIO[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,
       7,    0,   62,    2, 0x06 /* Public */,
       8,    0,   63,    2, 0x06 /* Public */,
       9,    1,   64,    2, 0x06 /* Public */,
      11,    1,   67,    2, 0x06 /* Public */,
      12,    1,   70,    2, 0x06 /* Public */,
      14,    1,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void midiIO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        midiIO *_t = static_cast<midiIO *>(_o);
        switch (_id) {
        case 0: _t->errorSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->replyMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->midiFinished(); break;
        case 3: _t->started(); break;
        case 4: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setStatusdBugMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (midiIO::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::errorSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (midiIO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::replyMsg)) {
                *result = 1;
            }
        }
        {
            typedef void (midiIO::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::midiFinished)) {
                *result = 2;
            }
        }
        {
            typedef void (midiIO::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::started)) {
                *result = 3;
            }
        }
        {
            typedef void (midiIO::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::setStatusSymbol)) {
                *result = 4;
            }
        }
        {
            typedef void (midiIO::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::setStatusProgress)) {
                *result = 5;
            }
        }
        {
            typedef void (midiIO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::setStatusMessage)) {
                *result = 6;
            }
        }
        {
            typedef void (midiIO::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&midiIO::setStatusdBugMessage)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject midiIO::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_midiIO.data,
      qt_meta_data_midiIO,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *midiIO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *midiIO::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_midiIO.stringdata))
        return static_cast<void*>(const_cast< midiIO*>(this));
    return QThread::qt_metacast(_clname);
}

int midiIO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void midiIO::errorSignal(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void midiIO::replyMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void midiIO::midiFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void midiIO::started()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void midiIO::setStatusSymbol(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void midiIO::setStatusProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void midiIO::setStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void midiIO::setStatusdBugMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
