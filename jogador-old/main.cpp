#include <QtGui/QApplication>
#include <QWidget>
#include <QDebug>
#include <QTimer>

#include "pivo.h"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    QWidget
    ui;

    ui.resize(210,510);

    ui.show();

    Tabuleiro::XyView
    pos(50,50);

    Tabuleiro::Pivo
    pivozinho(6,QColor(0,0,0),pos, &ui);

//    pivozinho.rotaciona();


    return a.exec();
}
