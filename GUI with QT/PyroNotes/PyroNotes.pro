QT += core gui printsupport texttospeech multimedia sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmaster.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    notewindow.cpp \
    sketchfcompanion.cpp \
    sketchform.cpp \
    table.cpp

HEADERS += \
    dbmaster.h \
    form.h \
    mainwindow.h \
    notewindow.h \
    sketchfcompanion.h \
    sketchform.h \
    table.h

FORMS += \
    dbmaster.ui \
    form.ui \
    mainwindow.ui \
    notewindow.ui \
    sketchfcompanion.ui \
    sketchform.ui \
    table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
