/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.9.9
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // /Users/caoruoxuan/Desktop/ypuc_oliver/avatar/default.jpg
  
  
  
static const unsigned char qt_resource_data[2088] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // avatar
  0x0,0x6,
  0x6,0x8c,0x8a,0x82,
  0x0,0x61,
  0x0,0x76,0x0,0x61,0x0,0x74,0x0,0x61,0x0,0x72,
    // default.jpg
  0x0,0xb,
  0xc,0xe2,0x28,0x67,
  0x0,0x64,
  0x0,0x65,0x0,0x66,0x0,0x61,0x0,0x75,0x0,0x6c,0x0,0x74,0x0,0x2e,0x0,0x6a,0x0,0x70,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/avatar
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/avatar/default.jpg
  0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x81,0xa9,0x84,0x70,0x70,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_avatar)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_avatar)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_avatar)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_avatar)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_avatar)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_avatar)(); }
   } dummy;
}
