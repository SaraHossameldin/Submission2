QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Button.cpp \
    ball.cpp \
    bar.cpp \
    block.cpp \
    coin.cpp \
    game.cpp \
    health.cpp \
    level.cpp \
    main.cpp \
    paddle.cpp \
    score.cpp

HEADERS += \
    Button.h \
    ball.h \
    bar.h \
    block.h \
    coin.h \
    game.h \
    health.h \
    level.h \
    paddle.h \
    Q_OBJECT \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Rec.qrc
