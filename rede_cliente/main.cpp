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

    Conexao conn;

    conn.conectar("192.168.1.102", 6969);

    Tradutor ahh;

    ahh.setConexao(&conn);


    QLineEdit* linha = new QLineEdit();

    QObject::connect(linha, SIGNAL(textEdited(QString)), &ahh, SLOT(chat(QString)));

    linha->show();

    return app.exec();
}
