/****************************************************************************
** Meta object code from reading C++ file 'summaryDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/summaryDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'summaryDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_summaryDialog_t {
    QByteArrayData data[7];
    char stringdata[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_summaryDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_summaryDialog_t qt_meta_stringdata_summaryDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "summaryDialog"
QT_MOC_LITERAL(1, 14, 4), // "view"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 6), // "cancel"
QT_MOC_LITERAL(4, 27, 9), // "printFile"
QT_MOC_LITERAL(5, 37, 12), // "printPreview"
QT_MOC_LITERAL(6, 50, 6) // "saveAs"

    },
    "summaryDialog\0view\0\0cancel\0printFile\0"
    "printPreview\0saveAs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_summaryDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void summaryDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        summaryDialog *_t = static_cast<summaryDialog *>(_o);
        switch (_id) {
        case 0: _t->view(); break;
        case 1: _t->cancel(); break;
        case 2: _t->printFile(); break;
        case 3: _t->printPreview(); break;
        case 4: _t->saveAs(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject summaryDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_summaryDialog.data,
      qt_meta_data_summaryDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *summaryDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *summaryDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_summaryDialog.stringdata))
        return static_cast<void*>(const_cast< summaryDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int summaryDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
