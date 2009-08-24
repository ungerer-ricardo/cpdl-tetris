#ifndef TRADUTOR_H
#define TRADUTOR_H

#include <QObject>
#include "conexao.h"

namespace Rede_Cliente
{
    enum TipoComando{
        INIT,
        NOVO,
        DOWN,
        CHAT,
        STAR,
        BUTT
    };

    typedef struct {
        TipoComando comando;
        int idJogador;
        int segundoInt;
        QString segundoStr;
    }Comando;

    class Tradutor : public QObject
    {
        Q_OBJECT

    public:
        Tradutor(QObject * = 0);

        void
        setConexao(Conexao *);

    public slots:

        void
        chat(QString);

        void
        incommingMessage(QString);

    protected:

        Comando
        traduzir(QString);

        int
        getPrimeiroParametro(QString);

        QString
        getSegundoParametroStr(QString);

        int
        getSegundoParametroInt(QString);

    private:
        Conexao *conexao;

        QString idJogador;

    signals:

    };
}

#endif // TRADUTOR_H
