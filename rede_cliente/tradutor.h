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
        BUTT,
        ENCA
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

        void
        setConexao(QString, quint16);

    public slots:

        void
        chat(QString);

        void
        rotacao();

        void
        movimentaDireita();

        void
        movimentaEsquerda();

        void
        encaixe();

        void
        incomingMessage(QString);

        void
        connectSuccessSlot();

    signals:

        void
        startjogo( qint8 descendo, qint8 proxima );

        void
        novapeca( qint8 nova );

        void
        button( int );

        void
        connectSuccessSignal();

        void
        connectFailureSignal();

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

        QWidget *tabuleiro;
    };
}

#endif // TRADUTOR_H
