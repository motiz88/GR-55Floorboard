/****************************************************************************
** Meta object code from reading C++ file 'summaryDialogSystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/summaryDialogSystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'summaryDialogSystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_summaryDialogSystem_t {
    QByteArrayData data[14];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_summaryDialogSystem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_summaryDialogSystem_t qt_meta_stringdata_summaryDialogSystem = {
    {
QT_MOC_LITERAL(0, 0, 19), // "summaryDialogSystem"
QT_MOC_LITERAL(1, 20, 15), // "setStatusSymbol"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "value"
QT_MOC_LITERAL(4, 43, 17), // "setStatusProgress"
QT_MOC_LITERAL(5, 61, 16), // "setStatusMessage"
QT_MOC_LITERAL(6, 78, 7), // "message"
QT_MOC_LITERAL(7, 86, 11), // "systemReply"
QT_MOC_LITERAL(8, 98, 8), // "replyMsg"
QT_MOC_LITERAL(9, 107, 6), // "cancel"
QT_MOC_LITERAL(10, 114, 9), // "printFile"
QT_MOC_LITERAL(11, 124, 6), // "saveAs"
QT_MOC_LITERAL(12, 131, 8), // "makeList"
QT_MOC_LITERAL(13, 140, 15) // "makeMidiMapList"

    },
    "summaryDialogSystem\0setStatusSymbol\0"
    "\0value\0setStatusProgress\0setStatusMessage\0"
    "message\0systemReply\0replyMsg\0cancel\0"
    "printFile\0saveAs\0makeList\0makeMidiMapList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_summaryDialogSystem[] = {

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
       5,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   68,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,
      12,    0,   74,    2, 0x0a /* Public */,
      13,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void summaryDialogSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        summaryDialogSystem *_t = static_cast<summaryDialogSystem *>(_o);
        switch (_id) {
        case 0: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->systemReply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->cancel(); break;
        case 5: _t->printFile(); break;
        case 6: _t->saveAs(); break;
        case 7: _t->makeList(); break;
        case 8: _t->makeMidiMapList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (summaryDialogSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&summaryDialogSystem::setStatusSymbol)) {
                *result = 0;
            }
        }
        {
            typedef void (summaryDialogSystem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&summaryDialogSystem::setStatusProgress)) {
                *result = 1;
            }
        }
        {
            typedef void (summaryDialogSystem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&summaryDialogSystem::setStatusMessage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject summaryDialogSystem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_summaryDialogSystem.data,
      qt_meta_data_summaryDialogSystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *summaryDialogSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *summaryDialogSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_summaryDialogSystem.stringdata))
        return static_cast<void*>(const_cast< summaryDialogSystem*>(this));
    return QWidget::qt_metacast(_clname);
}

int summaryDialogSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void summaryDialogSystem::setStatusSymbol(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void summaryDialogSystem::setStatusProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void summaryDialogSystem::setStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
