QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose.cpp \
    congrats.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    main.cpp \
    mainwindow.cpp \
    report.cpp \
    signin.cpp \
    signin2.cpp \
    signup.cpp \
    startgame.cpp

HEADERS += \
    choose.h \
    congrats.h \
    level1.h \
    level2.h \
    level3.h \
    mainwindow.h \
    report.h \
    signin.h \
    signin2.h \
    signup.h \
    startgame.h

FORMS += \
    choose.ui \
    congrats.ui \
    level1.ui \
    level2.ui \
    level3.ui \
    mainwindow.ui \
    report.ui \
    signin.ui \
    signin2.ui \
    signup.ui \
    startgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Pictures.qrc \
    Sounds.qrc
