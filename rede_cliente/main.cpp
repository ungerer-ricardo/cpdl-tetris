#include <QApplication>
#include <iostream>

#include "conexao.h"
#include "tradutor.h"

#include <QDebug>

#include <QLineEdit>

using namespace Rede_Cliente;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

//    Tradutor *tradutor = new Tradutor();
//    tradutor->conectar("192.168.1.100", 6969, "Joselito");
//
//    tradutor->show();
//
//
//    QLineEdit* linha = new QLineEdit();
//
//    QObject::connect(linha, SIGNAL(textEdited(QString)), tradutor, SLOT(chat(QString)));
//
//    linha->show();

    return app.exec();
}
