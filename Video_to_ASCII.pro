TEMPLATE = app
QT += core gui widgets

CONFIG += c++17 cmdline

# Указывать библиотеки следует с использованием правильных флагов, как показано ниже:
INCLUDEPATH += "/usr/local/Cellar/opencv/4.8.0_1/include/opencv4"
DEPENDPATH += "/usr/local/Cellar/opencv/4.8.0_1/include/opencv4"

LIBS += -L"/usr/local/Cellar/opencv/4.8.0_1/lib"

# Для режима Release
CONFIG(release, debug|release) {
    # Добавьте флаг -v для компилятора
    QMAKE_CXXFLAGS += -v

    # Определение библиотек для режима Release
    LIBS += -lopencv_core.4.8.0 -lopencv_highgui.4.8.0 -lopencv_imgproc.4.8.0 -lopencv_videoio.4.8.0
}

# Для режима Debug
CONFIG(debug, debug|release) {
    # Добавьте флаг -v для компилятора
    QMAKE_CXXFLAGS += -v

    # Определение библиотек для режима Debug
    LIBS += -lopencv_core.4.8.0 -lopencv_highgui.4.8.0 -lopencv_imgproc.4.8.0 -lopencv_videoio.4.8.0
}

SOURCES += main.cpp



