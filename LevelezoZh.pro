TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        arkhamairlines.cpp \
        atlantisairlines.cpp \
        main.cpp \
        plannerinterface.cpp \
        routefinder.cpp

HEADERS += \
	arkhamairlines.h \
	atlantisairlines.h \
	plannerinterface.h \
	routefinder.h
