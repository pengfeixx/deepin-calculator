######################################################################
# Automatically generated by qmake (3.1) Sat Aug 11 21:22:49 2018
######################################################################

QT += core gui widgets svg

TEMPLATE = app
TARGET = deepin-calculator
INCLUDEPATH += .
CONFIG += c++11 link_pkgconfig
QT += dtkwidget dtkgui

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += mainwindow.h \
           dsettings.h \
           utils.h \
           core/book.h \
           core/constants.h \
           core/errors.h \
           core/evaluator.h \
           core/functions.h \
           core/numberformatter.h \
           core/opcode.h \
           core/pageserver.h \
           core/session.h \
           core/sessionhistory.h \
           core/settings.h \
           core/userfunction.h \
           core/variable.h \
           math/cmath.h \
           math/cnumberparser.h \
           math/floatcommon.h \
           math/floatconfig.h \
           math/floatconst.h \
           math/floatconvert.h \
           math/floaterf.h \
           math/floatexp.h \
           math/floatgamma.h \
           math/floathmath.h \
           math/floatincgamma.h \
           math/floatio.h \
           math/floatipower.h \
           math/floatlog.h \
           math/floatlogic.h \
           math/floatlong.h \
           math/floatnum.h \
           math/floatpower.h \
           math/floatseries.h \
           math/floattrig.h \
           math/hmath.h \
           math/number.h \
           math/quantity.h \
           math/rational.h \
           math/units.h \
           modules/basicmodule.h \
           modules/expressionbar.h \
           modules/simplelistdelegate.h \
           modules/simplelistmodel.h \
           modules/simplelistview.h \
           widgets/basickeypad.h \
           widgets/iconbutton.h \
           widgets/inputedit.h \
           widgets/scientifickeypad.h \
           widgets/textbutton.h \
    widgets/equalbutton.h \
    widgets/memorybutton.h \
    modules/memoryitemwidget.h \
    widgets/memorykeypad.h \
    modules/memorywidget.h \
    modules/memorylistwidget.h
SOURCES += main.cpp \
           mainwindow.cpp \
           dsettings.cpp \
           utils.cpp \
           core/book.cpp \
           core/constants.cpp \
           core/evaluator.cpp \
           core/functions.cpp \
           core/numberformatter.cpp \
           core/opcode.cpp \
           core/pageserver.cpp \
           core/session.cpp \
           core/sessionhistory.cpp \
           core/settings.cpp \
           core/userfunction.cpp \
           core/variable.cpp \
           math/cmath.cpp \
           math/cnumberparser.cpp \
           math/floatcommon.c \
           math/floatconst.c \
           math/floatconvert.c \
           math/floaterf.c \
           math/floatexp.c \
           math/floatgamma.c \
           math/floathmath.c \
           math/floatincgamma.c \
           math/floatio.c \
           math/floatipower.c \
           math/floatlog.c \
           math/floatlogic.c \
           math/floatlong.c \
           math/floatnum.c \
           math/floatpower.c \
           math/floatseries.c \
           math/floattrig.c \
           math/hmath.cpp \
           math/number.c \
           math/quantity.cpp \
           math/rational.cpp \
           math/units.cpp \
           modules/basicmodule.cpp \
           modules/expressionbar.cpp \
           modules/simplelistdelegate.cpp \
           modules/simplelistmodel.cpp \
           modules/simplelistview.cpp \
           widgets/basickeypad.cpp \
           widgets/iconbutton.cpp \
           widgets/inputedit.cpp \
           widgets/scientifickeypad.cpp \
           widgets/textbutton.cpp \
    widgets/equalbutton.cpp \
    widgets/memorybutton.cpp \
    modules/memoryitemwidget.cpp \
    widgets/memorykeypad.cpp \
    modules/memorywidget.cpp \
    modules/memorylistwidget.cpp

RESOURCES += deepin-calculator.qrc
TRANSLATIONS += $$PWD/translations/deepin-calculator.ts \
                $$PWD/translations/deepin-calculator_zh_CN.ts \
                $$PWD/translations/deepin-calculator_en_US.ts

isEmpty(BINDIR):BINDIR=/usr/bin
isEmpty(APPDIR):APPDIR=/usr/share/applications
isEmpty(DSRDIR):DSRDIR=/usr/share/deepin-calculator

# Automating generation .qm files from .ts files
!system($$PWD/translate_generation.sh): error("Failed to generate translation")

target.path = $$INSTROOT$$BINDIR
icon_files.path = $$PREFIX/share/icons/hicolor/scalable/apps/
icon_files.files = $$PWD/images/deepin-calculator.svg

desktop.path = $$INSTROOT$$APPDIR
desktop.files = deepin-calculator.desktop

manual.path = /usr/share/dman/
manual.files = $$PWD/dman/*

translations.path = /usr/share/deepin-calculator/translations/
translations.files = translations/*.qm

INSTALLS += target desktop icon_files translations manual
