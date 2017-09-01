/****************************************************************************
** Meta object code from reading C++ file 'customMultiComboBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customMultiComboBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customMultiComboBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customMultiComboBox_t {
    QByteArrayData data[10];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customMultiComboBox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customMultiComboBox_t qt_meta_stringdata_customMultiComboBox = {
    {
QT_MOC_LITERAL(0, 0, 19), // "customMultiComboBox"
QT_MOC_LITERAL(1, 20, 12), // "updateSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "valueChanged"
QT_MOC_LITERAL(4, 47, 5), // "index"
QT_MOC_LITERAL(5, 53, 18), // "dialogUpdateSignal"
QT_MOC_LITERAL(6, 72, 12), // "changedIndex"
QT_MOC_LITERAL(7, 85, 8), // "MPTReply"
QT_MOC_LITERAL(8, 94, 14), // "QList<QString>"
QT_MOC_LITERAL(9, 109, 8) // "replyMsg"

    },
    "customMultiComboBox\0updateSignal\0\0"
    "valueChanged\0index\0dialogUpdateSignal\0"
    "changedIndex\0MPTReply\0QList<QString>\0"
    "replyMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customMultiComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    0x80000000 | 8, QMetaType::QString,    9,

       0        // eod
};

void customMultiComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customMultiComboBox *_t = static_cast<customMultiComboBox *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->dialogUpdateSignal(); break;
        case 3: _t->changedIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { QList<QString> _r = _t->MPTReply((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customMultiComboBox::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customMultiComboBox::updateSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject customMultiComboBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customMultiComboBox.data,
      qt_meta_data_customMultiComboBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customMultiComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customMultiComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customMultiComboBox.stringdata))
        return static_cast<void*>(const_cast< customMultiComboBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int customMultiComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void customMultiComboBox::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
