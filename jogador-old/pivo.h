#ifndef PECA_H
#define PECA_H

#include <QPair>
#include <QPoint>
#include <QTimer>
#include <QVector>
#include <QWidget>

#include "mapapecas.h"
#include "pecinha.h"


namespace Tabuleiro
{
    class Pivo : public Tabuleiro::Pecinha
    {
        Q_OBJECT

        public:
            Pivo( qint8, QColor, Tabuleiro::XyView, QWidget* _parent );

            ~Pivo( );

        public slots:
            void
            rotaciona( );

            void
            desce( );

        signals:
            void
            mudou( Tabuleiro::XyView );

        private:
            QTimer*
            timer;

            QTimer*
            timer2;

            qint8
            tipoPecaInt;

            Tabuleiro::TipoPeca
            peca;
            
            QVector<Tabuleiro::Pecinha*>
            agregadas;

            QString
            cor;

            Tabuleiro::CoordenadaMapaBits
            ondeEuTo;

            Tabuleiro::XyView
            ondeEuToExibido;

            void
            configuraAgregados( );

            void
            desenha();
    };
}

#endif // PECA_H
