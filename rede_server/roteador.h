#ifndef ROTEADOR_H
#define ROTEADOR_H

#include <QList>
#include <QObject>

#include "./jogador.h"
#include "./ouvinte.h"
#include "../lib/tradutor.h"

namespace Rede_Server
{
    class Roteador : public QObject
    {
        Q_OBJECT
    public:

        Roteador( QObject* _parent = 0 );

        ~Roteador();

    signals:

        void
        broadcast( QByteArray& _dado );

    public slots:

        void
        novoJogador( Jogador* _novo_jogador );

        void
        recebeDado( QByteArray _dado );

    protected:

        void
        processaComando( ComandoParseado& _comando );

    private:

        QList<Jogador*>
        listaJogadores;

        Ouvinte*
        ouvinte;

        Tradutor
        tradutor;
    };

}
#endif // ROTEADOR_H
