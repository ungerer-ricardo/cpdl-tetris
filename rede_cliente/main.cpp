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

    Tradutor ahh;

    ahh.setConexao("10.90.150.233", 9999);


    QLineEdit* linha = new QLineEdit();

    QObject::connect(linha, SIGNAL(textEdited(QString)), &ahh, SLOT(chat(QString)));

    linha->show();

    return app.exec();
}
