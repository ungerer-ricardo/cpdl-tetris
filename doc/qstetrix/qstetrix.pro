QT += script network
CONFIG += uitools
HEADERS = tetrixboard.h \
    server.h \
    client.h
SOURCES = main.cpp \
    tetrixboard.cpp \
    server.cpp \
    client.cpp
FORMS = tetrixwindow.ui
RESOURCES = tetrix.qrc
contains(QT_CONFIG, scripttools):QT += scripttools

# install
target.path = $$[QT_INSTALL_EXAMPLES]/script/qstetrix
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    qstetrix.pro \
    *.js
sources.path = $$[QT_INSTALL_EXAMPLES]/script/qstetrix
INSTALLS += target \
    sources
