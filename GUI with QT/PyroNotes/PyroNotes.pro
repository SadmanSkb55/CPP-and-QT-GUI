QT += core gui printsupport texttospeech multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    notewindow.cpp \
    scribblearea.cpp \
    sketcher.cpp \
    table.cpp

HEADERS += \
    form.h \
    mainwindow.h \
    notewindow.h \
    scribblearea.h \
    sketcher.h \
    table.h

FORMS += \
    form.ui \
    mainwindow.ui \
    notewindow.ui \
    scribblearea.ui \
    sketcher.ui \
    table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
