#ifndef ECHO_GLOBAL_HPP
#define ECHO_GLOBAL_HPP

#include <QtCore/QtCore>

#if defined(ECHO_LIBRARY)
#   define ECHO_SHARED_EXPORT Q_DECL_EXPORT
#else
#   define ECHO_SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif
