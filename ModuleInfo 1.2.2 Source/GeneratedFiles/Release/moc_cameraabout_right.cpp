/****************************************************************************
** Meta object code from reading C++ file 'cameraabout_right.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cameraabout_right.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameraabout_right.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraAbout_Right_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraAbout_Right_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraAbout_Right_t qt_meta_stringdata_CameraAbout_Right = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CameraAbout_Right"
QT_MOC_LITERAL(1, 18, 11), // "sig_save_ok"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "slot_setCameraData"
QT_MOC_LITERAL(4, 50, 20), // "QList<imrCameraData>"
QT_MOC_LITERAL(5, 71, 4), // "data"
QT_MOC_LITERAL(6, 76, 17), // "slot_setCameraImu"
QT_MOC_LITERAL(7, 94, 3) // "imu"

    },
    "CameraAbout_Right\0sig_save_ok\0\0"
    "slot_setCameraData\0QList<imrCameraData>\0"
    "data\0slot_setCameraImu\0imu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraAbout_Right[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x08 /* Private */,
       6,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Double,    7,

       0        // eod
};

void CameraAbout_Right::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraAbout_Right *_t = static_cast<CameraAbout_Right *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_save_ok(); break;
        case 1: _t->slot_setCameraData((*reinterpret_cast< QList<imrCameraData>(*)>(_a[1]))); break;
        case 2: _t->slot_setCameraImu((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CameraAbout_Right::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraAbout_Right::sig_save_ok)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CameraAbout_Right::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraAbout_Right.data,
      qt_meta_data_CameraAbout_Right,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CameraAbout_Right::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraAbout_Right::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraAbout_Right.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CameraAbout_Right::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CameraAbout_Right::sig_save_ok()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
