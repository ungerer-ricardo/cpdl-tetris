#ifndef ROTEADOR_H
#define ROTEADOR_H

#include <QList>
#include <QObject>

#include "./jogador.h"
#include "./ouvinte.h"

namespace Rede_Server
{
    class Roteador : public QObject
    {
        Q_OBJECT
    public:

        Roteador( QObject* _parent = 0 );

        ~Roteador();

        void
        stopListen();

    public slots:

        void
        novoJogador( Jogador* _novo_jogador );

        void
        recebeDado( QString _dado );

    protected slots:

        void
        jogadorCaiu( Jogador* _com_erro );

    private:

        QList<Jogador*>
        listaJogadores;

        Ouvinte*
        ouvinte;

    signals:

        void
        broadcast( QString _dado );
    };

}
#endif // ROTEADOR_H
