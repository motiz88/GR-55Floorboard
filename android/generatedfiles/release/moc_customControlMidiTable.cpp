/****************************************************************************
** Meta object code from reading C++ file 'customControlMidiTable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customControlMidiTable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customControlMidiTable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customControlMidiTable_t {
    QByteArrayData data[7];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customControlMidiTable_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customControlMidiTable_t qt_meta_stringdata_customControlMidiTable = {
    {
QT_MOC_LITERAL(0, 0, 22), // "customControlMidiTable"
QT_MOC_LITERAL(1, 23, 12), // "updateSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "updateDisplay"
QT_MOC_LITERAL(4, 51, 4), // "text"
QT_MOC_LITERAL(5, 56, 19), // "currentIndexChanged"
QT_MOC_LITERAL(6, 76, 5) // "index"

    },
    "customControlMidiTable\0updateSignal\0"
    "\0updateDisplay\0text\0currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customControlMidiTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       5,    1,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void customControlMidiTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customControlMidiTable *_t = static_cast<customControlMidiTable *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customControlMidiTable::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlMidiTable::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customControlMidiTable::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlMidiTable::updateDisplay)) {
                *result = 1;
            }
        }
        {
            typedef void (customControlMidiTable::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlMidiTable::currentIndexChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject customControlMidiTable::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customControlMidiTable.data,
      qt_meta_data_customControlMidiTable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customControlMidiTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customControlMidiTable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customControlMidiTable.stringdata))
        return static_cast<void*>(const_cast< customControlMidiTable*>(this));
    return QWidget::qt_metacast(_clname);
}

int customControlMidiTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void customControlMidiTable::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customControlMidiTable::updateDisplay(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customControlMidiTable::currentIndexChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE