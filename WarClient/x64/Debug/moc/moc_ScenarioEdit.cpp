/****************************************************************************
** Meta object code from reading C++ file 'ScenarioEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../UI/ScenarioEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScenarioEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScenarioEdit_t {
    QByteArrayData data[15];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScenarioEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScenarioEdit_t qt_meta_stringdata_ScenarioEdit = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ScenarioEdit"
QT_MOC_LITERAL(1, 13, 20), // "on_ModelName_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 52, 4), // "item"
QT_MOC_LITERAL(5, 57, 1), // "i"
QT_MOC_LITERAL(6, 59, 26), // "on_mouseBackButton_clicked"
QT_MOC_LITERAL(7, 86, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(8, 110, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(9, 134, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(10, 149, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 162, 5), // "event"
QT_MOC_LITERAL(12, 168, 15), // "mousePressEvent"
QT_MOC_LITERAL(13, 184, 21), // "slot_ModelBtn_Clicked"
QT_MOC_LITERAL(14, 206, 13) // "slot_doChoose"

    },
    "ScenarioEdit\0on_ModelName_clicked\0\0"
    "QTreeWidgetItem*\0item\0i\0"
    "on_mouseBackButton_clicked\0"
    "on_actionSave_triggered\0on_actionOpen_triggered\0"
    "mouseMoveEvent\0QMouseEvent*\0event\0"
    "mousePressEvent\0slot_ModelBtn_Clicked\0"
    "slot_doChoose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScenarioEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,
      13,    0,   68,    2, 0x08 /* Private */,
      14,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void ScenarioEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScenarioEdit *_t = static_cast<ScenarioEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ModelName_clicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_mouseBackButton_clicked(); break;
        case 2: _t->on_actionSave_triggered(); break;
        case 3: _t->on_actionOpen_triggered(); break;
        case 4: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->slot_ModelBtn_Clicked(); break;
        case 7: _t->slot_doChoose((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ScenarioEdit::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ScenarioEdit.data,
      qt_meta_data_ScenarioEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScenarioEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScenarioEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScenarioEdit.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ScenarioEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
