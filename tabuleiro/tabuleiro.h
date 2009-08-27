#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <QtGui/QWidget>
#include <QKeyEvent>

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

        void
        colidiu( );

        void
        onKeyPress( int );

        void
        procuraLinhasCheias( );

        void
        apagaLinhaCheia( Tab::XyView );

        void
        setLevel( );

        void
        setPontuacao( );

    signals:
        void
        encaixe( );

        void
        gameover( int pontuacao );

    #if !defined(Q_MOC_RUN)
    private: // can only be emitted by TetrixBoard
    #endif
        void
        keyPressed( int );

        void
        linhaCheia( Tab::XyView );

        void
        procuraLinhas( );

        void
        levelMudou( );

        void
        pontuacaoMudou( );

    protected:
        void
        keyPressEvent( QKeyEvent* );

    protected:
        QTimer*
        timer;

        unsigned int
        pontuacao;

        unsigned int
        level;

        unsigned int
        numeroPecasUtilizadas;

        Tab::Pivo*
        currentPiece;

        Tab::Pivo*
        previewPiece;

        void
        desceLinhas( Tab::XyView );

        unsigned int
        getTimeOut( );

    private:
        Ui::Tabuleiro *ui;
};

#endif // TABULEIRO_H
