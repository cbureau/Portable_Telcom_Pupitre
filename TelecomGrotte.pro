#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T15:39:29
#
#-------------------------------------------------

QT       += core gui androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TelecomGrotte
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    androidrfcomm.cpp

HEADERS  += mainwindow.h \
    androidrfcomm.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

