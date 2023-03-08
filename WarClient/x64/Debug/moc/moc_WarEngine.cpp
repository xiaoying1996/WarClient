/****************************************************************************
** Meta object code from reading C++ file 'WarEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WarEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WarEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WarEngine_t {
    QByteArrayData data[12];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WarEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WarEngine_t qt_meta_stringdata_WarEngine = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WarEngine"
QT_MOC_LITERAL(1, 10, 10), // "SendMsgLog"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "SendSysTime"
QT_MOC_LITERAL(4, 34, 12), // "SendModelLog"
QT_MOC_LITERAL(5, 47, 13), // "handleTimeout"
QT_MOC_LITERAL(6, 61, 20), // "slot_ChangePosEnable"
QT_MOC_LITERAL(7, 82, 1), // "i"
QT_MOC_LITERAL(8, 84, 23), // "slot_ChangeAttackEnable"
QT_MOC_LITERAL(9, 108, 24), // "slot_ChangeDestoryEnable"
QT_MOC_LITERAL(10, 133, 20), // "slot_ChangeCmdEnable"
QT_MOC_LITERAL(11, 154, 18) // "slot_LengthChanged"

    },
    "WarEngine\0SendMsgLog\0\0SendSysTime\0"
    "SendModelLog\0handleTimeout\0"
    "slot_ChangePosEnable\0i\0slot_ChangeAttackEnable\0"
    "slot_ChangeDestoryEnable\0slot_ChangeCmdEnable\0"
    "slot_LengthChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WarEngine[] = {

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
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   68,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       8,    1,   72,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      11,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void WarEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WarEngine *_t = static_cast<WarEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendMsgLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendSysTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SendModelLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->handleTimeout(); break;
        case 4: _t->slot_ChangePosEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_ChangeAttackEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_ChangeDestoryEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_ChangeCmdEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_LengthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WarEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarEngine::SendMsgLog)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WarEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarEngine::SendSysTime)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WarEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarEngine::SendModelLog)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject WarEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WarEngine.data,
      qt_meta_data_WarEngine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WarEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WarEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WarEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WarEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void WarEngine::SendMsgLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WarEngine::SendSysTime(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WarEngine::SendModelLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
