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
            seta (QWidget*);

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

        private:
            qint8
            tipoPecaInt;

            Tab::TipoPeca
            peca;
            
            QVector<Tab::Pecinha*>
            agregadas;

            QString
            cor;

            Tab::CoordenadaMapaBits
            ondeEuTo;

            Tab::XyView
            ondeEuToExibido;

            void
            configuraAgregados( );

            void
            desenha();
    };
}

#endif // PECA_H
