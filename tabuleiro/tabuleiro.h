#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <QtGui/QWidget>

#include "basicos.h"
#include "pivo.h"

namespace Ui
{
    class Tabuleiro;
}

class Tabuleiro : public QWidget
{
    Q_OBJECT

    public:
        Tabuleiro( QWidget *parent = 0 );

        ~Tabuleiro( );

    public slots:
        void
        rotacionapeca();

        void
        movepeca( bool _direcao );

        void
        startjogo( qint8 descendo, qint8 proxima );

        void
        novapeca( qint8 nova );

    signals:
        void
        encaixe( );

        void
        gameover( int pontuacao );


    protected:
        QTimer*
        timer;

        QTimer*
        timer2;

        Tab::Pivo*
        currentPiece;

        Tab::Pivo*
        previewPiece;

    private:
        Ui::Tabuleiro *ui;
};

#endif // TABULEIRO_H
