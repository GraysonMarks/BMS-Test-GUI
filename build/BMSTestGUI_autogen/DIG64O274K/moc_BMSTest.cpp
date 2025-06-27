/****************************************************************************
** Meta object code from reading C++ file 'BMSTest.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../inc/BMSTest.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BMSTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_BMSTest_t {
    uint offsetsAndSizes[42];
    char stringdata0[8];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[3];
    char stringdata4[6];
    char stringdata5[11];
    char stringdata6[11];
    char stringdata7[4];
    char stringdata8[13];
    char stringdata9[8];
    char stringdata10[13];
    char stringdata11[9];
    char stringdata12[11];
    char stringdata13[13];
    char stringdata14[2];
    char stringdata15[13];
    char stringdata16[6];
    char stringdata17[16];
    char stringdata18[8];
    char stringdata19[10];
    char stringdata20[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_BMSTest_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_BMSTest_t qt_meta_stringdata_BMSTest = {
    {
        QT_MOC_LITERAL(0, 7),  // "BMSTest"
        QT_MOC_LITERAL(8, 18),  // "relayStatusUpdated"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 2),  // "id"
        QT_MOC_LITERAL(31, 5),  // "alive"
        QT_MOC_LITERAL(37, 10),  // "cycleCount"
        QT_MOC_LITERAL(48, 10),  // "logMessage"
        QT_MOC_LITERAL(59, 3),  // "msg"
        QT_MOC_LITERAL(63, 12),  // "testFinished"
        QT_MOC_LITERAL(76, 7),  // "allDead"
        QT_MOC_LITERAL(84, 12),  // "setRelayPort"
        QT_MOC_LITERAL(97, 8),  // "portName"
        QT_MOC_LITERAL(106, 10),  // "setDacPort"
        QT_MOC_LITERAL(117, 12),  // "setNumRelays"
        QT_MOC_LITERAL(130, 1),  // "n"
        QT_MOC_LITERAL(132, 12),  // "setThreshold"
        QT_MOC_LITERAL(145, 5),  // "volts"
        QT_MOC_LITERAL(151, 15),  // "setTestDuration"
        QT_MOC_LITERAL(167, 7),  // "seconds"
        QT_MOC_LITERAL(175, 9),  // "startTest"
        QT_MOC_LITERAL(185, 8)   // "stopTest"
    },
    "BMSTest",
    "relayStatusUpdated",
    "",
    "id",
    "alive",
    "cycleCount",
    "logMessage",
    "msg",
    "testFinished",
    "allDead",
    "setRelayPort",
    "portName",
    "setDacPort",
    "setNumRelays",
    "n",
    "setThreshold",
    "volts",
    "setTestDuration",
    "seconds",
    "startTest",
    "stopTest"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_BMSTest[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   74,    2, 0x06,    1 /* Public */,
       6,    1,   81,    2, 0x06,    5 /* Public */,
       8,    1,   84,    2, 0x06,    7 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   87,    2, 0x02,    9 /* Public */,
      12,    1,   90,    2, 0x02,   11 /* Public */,
      13,    1,   93,    2, 0x02,   13 /* Public */,
      15,    1,   96,    2, 0x02,   15 /* Public */,
      17,    1,   99,    2, 0x02,   17 /* Public */,
      19,    0,  102,    2, 0x02,   19 /* Public */,
      20,    0,  103,    2, 0x02,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BMSTest::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_BMSTest.offsetsAndSizes,
    qt_meta_data_BMSTest,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_BMSTest_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BMSTest, std::true_type>,
        // method 'relayStatusUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'logMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'testFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setRelayPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setDacPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setNumRelays'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setThreshold'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setTestDuration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'startTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BMSTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BMSTest *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->relayStatusUpdated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->testFinished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->setRelayPort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->setDacPort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setNumRelays((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setThreshold((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->setTestDuration((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->startTest(); break;
        case 9: _t->stopTest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BMSTest::*)(int , bool , int );
            if (_t _q_method = &BMSTest::relayStatusUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BMSTest::*)(const QString & );
            if (_t _q_method = &BMSTest::logMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BMSTest::*)(bool );
            if (_t _q_method = &BMSTest::testFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *BMSTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BMSTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BMSTest.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BMSTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void BMSTest::relayStatusUpdated(int _t1, bool _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BMSTest::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BMSTest::testFinished(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
