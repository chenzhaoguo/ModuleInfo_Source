/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[30];
    char stringdata0[603];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "sig_imu_data_post"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "QList<string>"
QT_MOC_LITERAL(4, 44, 25), // "sig_camera_data_post_left"
QT_MOC_LITERAL(5, 70, 20), // "QList<imrCameraData>"
QT_MOC_LITERAL(6, 91, 24), // "sig_camera_imu_post_left"
QT_MOC_LITERAL(7, 116, 26), // "sig_camera_data_post_right"
QT_MOC_LITERAL(8, 143, 25), // "sig_camera_imu_post_right"
QT_MOC_LITERAL(9, 169, 25), // "showTimelimit_camera_show"
QT_MOC_LITERAL(10, 195, 23), // "showTimelimit_con_state"
QT_MOC_LITERAL(11, 219, 23), // "showTimelimit_work_show"
QT_MOC_LITERAL(12, 243, 20), // "showTimelimit_camera"
QT_MOC_LITERAL(13, 264, 17), // "showTimelimit_imu"
QT_MOC_LITERAL(14, 282, 26), // "on_module_info_min_clicked"
QT_MOC_LITERAL(15, 309, 28), // "on_module_info_close_clicked"
QT_MOC_LITERAL(16, 338, 24), // "on_collect_start_clicked"
QT_MOC_LITERAL(17, 363, 28), // "on_hmd_data_path_set_clicked"
QT_MOC_LITERAL(18, 392, 14), // "slot_save_isok"
QT_MOC_LITERAL(19, 407, 20), // "on_test_area_clicked"
QT_MOC_LITERAL(20, 428, 22), // "on_imu_collect_clicked"
QT_MOC_LITERAL(21, 451, 24), // "on_test_area_top_clicked"
QT_MOC_LITERAL(22, 476, 24), // "on_imu_data_stateChanged"
QT_MOC_LITERAL(23, 501, 5), // "state"
QT_MOC_LITERAL(24, 507, 27), // "on_camera_data_stateChanged"
QT_MOC_LITERAL(25, 535, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(26, 550, 12), // "QMouseEvent*"
QT_MOC_LITERAL(27, 563, 5), // "event"
QT_MOC_LITERAL(28, 569, 15), // "mousePressEvent"
QT_MOC_LITERAL(29, 585, 17) // "mouseReleaseEvent"

    },
    "MainWindow\0sig_imu_data_post\0\0"
    "QList<string>\0sig_camera_data_post_left\0"
    "QList<imrCameraData>\0sig_camera_imu_post_left\0"
    "sig_camera_data_post_right\0"
    "sig_camera_imu_post_right\0"
    "showTimelimit_camera_show\0"
    "showTimelimit_con_state\0showTimelimit_work_show\0"
    "showTimelimit_camera\0showTimelimit_imu\0"
    "on_module_info_min_clicked\0"
    "on_module_info_close_clicked\0"
    "on_collect_start_clicked\0"
    "on_hmd_data_path_set_clicked\0"
    "slot_save_isok\0on_test_area_clicked\0"
    "on_imu_collect_clicked\0on_test_area_top_clicked\0"
    "on_imu_data_stateChanged\0state\0"
    "on_camera_data_stateChanged\0mouseMoveEvent\0"
    "QMouseEvent*\0event\0mousePressEvent\0"
    "mouseReleaseEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,
       4,    1,  132,    2, 0x06 /* Public */,
       6,    1,  135,    2, 0x06 /* Public */,
       7,    1,  138,    2, 0x06 /* Public */,
       8,    1,  141,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  144,    2, 0x08 /* Private */,
      10,    0,  145,    2, 0x08 /* Private */,
      11,    0,  146,    2, 0x08 /* Private */,
      12,    0,  147,    2, 0x08 /* Private */,
      13,    0,  148,    2, 0x08 /* Private */,
      14,    0,  149,    2, 0x08 /* Private */,
      15,    0,  150,    2, 0x08 /* Private */,
      16,    0,  151,    2, 0x08 /* Private */,
      17,    0,  152,    2, 0x08 /* Private */,
      18,    0,  153,    2, 0x08 /* Private */,
      19,    0,  154,    2, 0x08 /* Private */,
      20,    0,  155,    2, 0x08 /* Private */,
      21,    0,  156,    2, 0x08 /* Private */,
      22,    1,  157,    2, 0x08 /* Private */,
      24,    1,  160,    2, 0x08 /* Private */,
      25,    1,  163,    2, 0x0a /* Public */,
      28,    1,  166,    2, 0x0a /* Public */,
      29,    1,  169,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Double,    2,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 26,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_imu_data_post((*reinterpret_cast< QList<string>(*)>(_a[1]))); break;
        case 1: _t->sig_camera_data_post_left((*reinterpret_cast< QList<imrCameraData>(*)>(_a[1]))); break;
        case 2: _t->sig_camera_imu_post_left((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->sig_camera_data_post_right((*reinterpret_cast< QList<imrCameraData>(*)>(_a[1]))); break;
        case 4: _t->sig_camera_imu_post_right((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->showTimelimit_camera_show(); break;
        case 6: _t->showTimelimit_con_state(); break;
        case 7: _t->showTimelimit_work_show(); break;
        case 8: _t->showTimelimit_camera(); break;
        case 9: _t->showTimelimit_imu(); break;
        case 10: _t->on_module_info_min_clicked(); break;
        case 11: _t->on_module_info_close_clicked(); break;
        case 12: _t->on_collect_start_clicked(); break;
        case 13: _t->on_hmd_data_path_set_clicked(); break;
        case 14: _t->slot_save_isok(); break;
        case 15: _t->on_test_area_clicked(); break;
        case 16: _t->on_imu_collect_clicked(); break;
        case 17: _t->on_test_area_top_clicked(); break;
        case 18: _t->on_imu_data_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_camera_data_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 21: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 22: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(QList<string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_imu_data_post)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QList<imrCameraData> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_camera_data_post_left)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_camera_imu_post_left)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QList<imrCameraData> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_camera_data_post_right)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_camera_imu_post_right)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_imu_data_post(QList<string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sig_camera_data_post_left(QList<imrCameraData> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sig_camera_imu_post_left(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sig_camera_data_post_right(QList<imrCameraData> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::sig_camera_imu_post_right(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
