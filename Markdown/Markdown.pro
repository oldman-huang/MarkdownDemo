QT -= gui
QT += core

TEMPLATE = lib
DEFINES += MARKDOWN_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/GnssReport/GnssReportRegistry.cpp \
    src/GnssReport/GnssPositionAccuracyReport.cpp \
    src/IReportFactory.cpp \
    src/IReport.cpp \
    src/ReportFactoryRegistry.cpp \
    src/ReportType.cpp \
    src/ReportContext.cpp \
    src/HtmlTableBase.cpp \
    src/HtmlTableCell.cpp \
    src/HtmlTable.cpp \
    src/MarkdownDocument.cpp \
    src/GnssReport/GnssReportFactory.cpp

HEADERS += \
    include/Markdown/Config.h \
    include/Markdown/HtmlTable.h \
    include/Markdown/HtmlTableBase.h \
    include/Markdown/HtmlTableCell.h \
    include/Markdown/IReport.h \
    include/Markdown/IReportFactory.h \
    include/Markdown/MarkdownDocument.h \
    include/Markdown/ReportContext.h \
    include/Markdown/ReportFactoryRegistry.h \
    include/Markdown/ReportType.h \
    src/GnssReport/GnssPositionAccuracyReport.h \
    src/GnssReport/GnssReportFactory.h \
    src/GnssReport/GnssReportRegistry.h
# Default rules for deployment.
unix {
    target.path = /usr/lib
}

!isEmpty(target.path): INSTALLS += target

msvc{
QMAKE_CFLAGS +=utf-8
QMAKE_CXXFLAGS +=utf-8
}

DLLDESTDIR = $$PWD/../bin
INCLUDEPATH +=$$PWD/include
