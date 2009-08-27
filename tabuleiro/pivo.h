#ifndef PECA_H
#define PECA_H

#include <QPair>
#include <QPoint>
#include <QTimer>
#include <QVector>
#include <QWidget>

#include "mapapecas.h"
#include "pecinha.h"


namespace Tab
{
    class Pivo : public Tab::Pecinha
    {
        Q_OBJECT

        public:
            Pivo( qint8, QColor, Tab::XyView, QWidget* _parent );

            ~Pivo( );

            void
            moveDireita( );

            void
            moveEsquerda( );

        public slots:
            void
            rotaciona( );

            void
            desce( );

        signals:
            void
            mudou( Tab::XyView );

            void
            colidiu( );

        private:
            qint8
            tipoPecaInt;

            Tab::TipoPeca
            peca;
            
            QVector<Tab::Pecinha*>
            agregadas;

            QColor
            cor;

            Tab::XyView
            ondeEuToExibido;

            void
            configuraAgregados( );

            bool
            possoColocarAqui( Tab::TipoPeca, Tab::XyView );
    };
}

#endif // PECA_H
