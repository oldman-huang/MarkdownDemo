#ifndef MARKDOWN_GLOBAL_H
#define MARKDOWN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MARKDOWN_LIBRARY)
#  define MARKDOWN_EXPORT Q_DECL_EXPORT
#else
#  define MARKDOWN_EXPORT Q_DECL_IMPORT
#endif

#endif // MARKDOWN_GLOBAL_H
