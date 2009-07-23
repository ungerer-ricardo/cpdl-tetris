#ifndef PECA_H
#define PECA_H

#include <QPair>
#include <QWidget>
#include <QVector>

#include "tipopeca.h"
#include "pecinha.h"


namespace Tabuleiro
{
    class Pivo : public Tabuleiro::Pecinha
    {
        Q_OBJECT

        public:
            Pivo(qint8, QString);
            
        public slots:
            void
            rotaciona();

            void
            desce();

        private:
            qint8
            tipoPecaInt;

            Tabuleiro::TipoPeca
            peca;
            
            QVector<Tabuleiro::Pecinha*>
            agregadas;

            QString
            cor;

            void
            configuraAgregados( );

            void
            desenha();
    };
}

#endif // PECA_H
