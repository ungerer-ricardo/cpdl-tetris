QT += network
FORMS += JanelaPrincipal.ui \
    ../tabuleiro/tabuleiro.ui
HEADERS += ../tabuleiro/tabuleiro.h \
    ../tabuleiro/pivo.h \
    ../tabuleiro/pecinha.h \
    ../tabuleiro/mapapecas.h \
    ../tabuleiro/basicos.h \
    janelaprincipal.h \
    ../rede_cliente/tradutor.h \
    ../rede_cliente/conexao.h
SOURCES += ../tabuleiro/tabuleiro.cpp \
    ../tabuleiro/pivo.cpp \
    ../tabuleiro/pecinha.cpp \
    ../tabuleiro/mapapecas.cpp \
    janelaprincipal.cpp \
    main.cpp \
    ../rede_cliente/tradutor.cpp \
    ../rede_cliente/conexao.cpp
