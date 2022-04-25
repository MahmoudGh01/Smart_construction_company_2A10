QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += charts
QT       += core gui sql
QT+=sql
QT  += printsupport
QT       += core gui sql network charts multimedia multimediawidgets serialport
QT += serialport
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
    arduino.cpp \
    batiment.cpp \
    connection.cpp \
    exportexcelobject.cpp \
    gestion_batiment.cpp \
    gestion_stock.cpp \
    histomod.cpp \
    historique.cpp \
    histosupp.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp \
    stat_combo.cpp \
    stockp.cpp

HEADERS += \
    arduino.h \
    batiment.h \
    connection.h \
    exportexcelobject.h \
    gestion_batiment.h \
    gestion_stock.h \
    histomod.h \
    historique.h \
    histosupp.h \
    mainwindow.h \
    qrcode.h \
    stat_combo.h \
    stockp.h

FORMS += \
    gestion_batiment.ui \
    gestion_stock.ui \
    mainwindow.ui \
    stat_combo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
