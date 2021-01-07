TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        arkhamairlines.cpp \
        arkhamplanner.cpp \
        atlantisairlines.cpp \
        main.cpp \
        plannerinterface.cpp \
        routefinder.cpp

HEADERS += \
	arkhamairlines.h \
	arkhamplanner.h \
	atlantisairlines.h \
	atlantisplanner.h \
	plannerinterface.h \
	routefinder.h
