QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_login_window.cpp \
    admin_second_window.cpp \
    main.cpp \
    mywindow.cpp \
    paybill.cpp \
    product_class.cpp \
    product_one_db.cpp \
    signup.cpp \
    user_profile_class.cpp \
    user_profile_window.cpp \
    usersecondwindow.cpp

HEADERS += \
    admin_login_window.h \
    admin_second_window.h \
    mywindow.h \
    paybill.h \
    product_class.h \
    product_one_db.h \
    signup.h \
    user_profile_class.h \
    user_profile_window.h \
    usersecondwindow.h

FORMS += \
    admin_login_window.ui \
    admin_second_window.ui \
    mywindow.ui \
    paybill.ui \
    product_class.ui \
    product_one_db.ui \
    signup.ui \
    user_profile_class.ui \
    user_profile_window.ui \
    usersecondwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Again_resources.qrc \
    another_Resources.qrc \
    resourcesFile.qrc

DISTFILES +=
