#ifndef ROTEADOR_H
#define ROTEADOR_H

#include <QList>
#include <QObject>
#include <QTime>

#include "./jogador.h"
#include "./ouvinte.h"

namespace Rede_Server
{
    class Roteador : public QObject
    {
        Q_OBJECT
    public:

        Roteador( int _njogadores, QObject* _parent = 0 );

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

    protected:

        void
        startJogo();

    private:

        QList<Jogador*>
        listaJogadores;

        Ouvinte*
        ouvinte;

        unsigned int
        njogadores;

        unsigned int
        current_id;

    signals:

        void
        broadcast( QString _dado );
    };

}
#endif // ROTEADOR_H
