#include <QtGui/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int b = 3;
    int c = 1;

    qDebug() << (b & c);

    return a.exec();
}
