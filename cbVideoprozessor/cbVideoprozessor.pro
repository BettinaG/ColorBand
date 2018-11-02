QT -= gui


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


INCLUDEPATH += $$(OPENCV_DIR)\include
LIBS += $$(OPENCV_DIR)\bin\libopencv_*.dll


SOURCES += \
        main.cpp \
    videoprozessor.cpp

HEADERS += \
    videoprozessor.h
