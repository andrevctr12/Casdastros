TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    dermatologia.c

include(deployment.pri)
qtcAddDeployment()

