/****************************************************************************
** Meta object code from reading C++ file 'WarClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WarClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WarClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WarClient_t {
    QByteArrayData data[25];
    char stringdata0[462];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WarClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WarClient_t qt_meta_stringdata_WarClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WarClient"
QT_MOC_LITERAL(1, 10, 13), // "sig_posEnable"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 1), // "i"
QT_MOC_LITERAL(4, 27, 16), // "sig_attackEnable"
QT_MOC_LITERAL(5, 44, 17), // "sig_destoryEnable"
QT_MOC_LITERAL(6, 62, 13), // "sig_cmdEnable"
QT_MOC_LITERAL(7, 76, 14), // "sig_SengLength"
QT_MOC_LITERAL(8, 91, 22), // "on_AddModelBtn_clicked"
QT_MOC_LITERAL(9, 114, 25), // "on_StartEngineBtn_clicked"
QT_MOC_LITERAL(10, 140, 22), // "on_OpenScenBtn_clicked"
QT_MOC_LITERAL(11, 163, 26), // "on_ServialModelBtn_clicked"
QT_MOC_LITERAL(12, 190, 28), // "on_DestoryedModelBtn_clicked"
QT_MOC_LITERAL(13, 219, 26), // "on_ScenarioEditBtn_clicked"
QT_MOC_LITERAL(14, 246, 25), // "on_Situation2DBtn_clicked"
QT_MOC_LITERAL(15, 272, 21), // "on_ConnectBtn_clicked"
QT_MOC_LITERAL(16, 294, 17), // "on_PosBox_toggled"
QT_MOC_LITERAL(17, 312, 20), // "on_attackBox_toggled"
QT_MOC_LITERAL(18, 333, 21), // "on_destoryBox_toggled"
QT_MOC_LITERAL(19, 355, 17), // "on_cmdBox_toggled"
QT_MOC_LITERAL(20, 373, 20), // "slot_EngineMsgRecved"
QT_MOC_LITERAL(21, 394, 3), // "msg"
QT_MOC_LITERAL(22, 398, 21), // "slot_EngineTimeRecved"
QT_MOC_LITERAL(23, 420, 22), // "slot_EngineModelRecved"
QT_MOC_LITERAL(24, 443, 18) // "slot_LengthChanged"

    },
    "WarClient\0sig_posEnable\0\0i\0sig_attackEnable\0"
    "sig_destoryEnable\0sig_cmdEnable\0"
    "sig_SengLength\0on_AddModelBtn_clicked\0"
    "on_StartEngineBtn_clicked\0"
    "on_OpenScenBtn_clicked\0"
    "on_ServialModelBtn_clicked\0"
    "on_DestoryedModelBtn_clicked\0"
    "on_ScenarioEditBtn_clicked\0"
    "on_Situation2DBtn_clicked\0"
    "on_ConnectBtn_clicked\0on_PosBox_toggled\0"
    "on_attackBox_toggled\0on_destoryBox_toggled\0"
    "on_cmdBox_toggled\0slot_EngineMsgRecved\0"
    "msg\0slot_EngineTimeRecved\0"
    "slot_EngineModelRecved\0slot_LengthChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WarClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    1,  122,    2, 0x06 /* Public */,
       5,    1,  125,    2, 0x06 /* Public */,
       6,    1,  128,    2, 0x06 /* Public */,
       7,    1,  131,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  134,    2, 0x08 /* Private */,
       9,    0,  135,    2, 0x08 /* Private */,
      10,    0,  136,    2, 0x08 /* Private */,
      11,    0,  137,    2, 0x08 /* Private */,
      12,    0,  138,    2, 0x08 /* Private */,
      13,    0,  139,    2, 0x08 /* Private */,
      14,    0,  140,    2, 0x08 /* Private */,
      15,    0,  141,    2, 0x08 /* Private */,
      16,    0,  142,    2, 0x08 /* Private */,
      17,    0,  143,    2, 0x08 /* Private */,
      18,    0,  144,    2, 0x08 /* Private */,
      19,    0,  145,    2, 0x08 /* Private */,
      20,    1,  146,    2, 0x08 /* Private */,
      22,    1,  149,    2, 0x08 /* Private */,
      23,    1,  152,    2, 0x08 /* Private */,
      24,    0,  155,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,

       0        // eod
};

void WarClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WarClient *_t = static_cast<WarClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_posEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_attackEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sig_destoryEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sig_cmdEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sig_SengLength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_AddModelBtn_clicked(); break;
        case 6: _t->on_StartEngineBtn_clicked(); break;
        case 7: _t->on_OpenScenBtn_clicked(); break;
        case 8: _t->on_ServialModelBtn_clicked(); break;
        case 9: _t->on_DestoryedModelBtn_clicked(); break;
        case 10: _t->on_ScenarioEditBtn_clicked(); break;
        case 11: _t->on_Situation2DBtn_clicked(); break;
        case 12: _t->on_ConnectBtn_clicked(); break;
        case 13: _t->on_PosBox_toggled(); break;
        case 14: _t->on_attackBox_toggled(); break;
        case 15: _t->on_destoryBox_toggled(); break;
        case 16: _t->on_cmdBox_toggled(); break;
        case 17: _t->slot_EngineMsgRecved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->slot_EngineTimeRecved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->slot_EngineModelRecved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->slot_LengthChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WarClient::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarClient::sig_posEnable)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WarClient::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarClient::sig_attackEnable)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WarClient::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarClient::sig_destoryEnable)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WarClient::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarClient::sig_cmdEnable)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (WarClient::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarClient::sig_SengLength)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject WarClient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WarClient.data,
      qt_meta_data_WarClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WarClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WarClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WarClient.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WarClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void WarClient::sig_posEnable(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WarClient::sig_attackEnable(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WarClient::sig_destoryEnable(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WarClient::sig_cmdEnable(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WarClient::sig_SengLength(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
