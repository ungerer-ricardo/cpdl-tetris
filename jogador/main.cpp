#include <QtGui/QApplication>
#include <QDebug>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    qDebug("pistola");

    return a.exec();
}
