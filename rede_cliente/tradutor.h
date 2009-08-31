#ifndef TRADUTOR_H
#define TRADUTOR_H

#include <QObject>
#include "conexao.h"

#include <QKeyEvent>
#include <QWidget>

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

    class Tradutor : public QWidget
    {
        Q_OBJECT


    public:

        Tradutor(QWidget * = 0);

        ~Tradutor();


    public slots:

//        slots de comunicação com a rede
        void
        conectar(QString, quint16, QString);

        void
        conexaoEstabelecidaInterna();

        void
        erroConexaoInterna(QAbstractSocket::SocketError);

        void
        incomingMessage(QString);

//        slots de transferencia de mensagens

        void
        chat(QString);

        void
        desce();

        void
        encaixe();

        void
        movimentaDireita();

        void
        movimentaEsquerda();

        void
        rotacao();


    protected:

//        void
//        keyPressEvent(QKeyEvent*);

        void
        enviaNome();

        void
        getListaJogadores(QString);

        int
        getPrimeiroParametro(QString);

        QString
        getSegundoParametroStr(QString);

        int
        getSegundoParametroInt(QString);

        Comando
        traduzir(QString);

    private:

        Conexao
        *conexao;

        QString
        nomeJogador;

        QString
        idJogador;


    signals:

        void
        chat(quint16, QString);

        void
        conexaoEstabelecida();

        void
        down(quint16);

        void
        descePeca(quint16);

        void
        erroConexao(QString);

        void
        movePecaDireita(quint16);

        void
        movePecaEsquerda(quint16);

        void
        novoJogador(quint16, QString);

        void
        rotacionaPeca(quint16);

        void
        startjogo(quint16, quint16);

        void
        novapeca(quint16, quint16);

    };
}

#endif // TRADUTOR_H
