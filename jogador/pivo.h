#ifndef PECA_H
#define PECA_H

#include <QPair>
#include <QWidget>

#include "tipopeca.h"
#include "pecinha.h"


namespace Tabuleiro
{
    class Pivo : public Pecinha
    {
        Q_OBJECT

        public:
            Pivo(qint8 = 0);
            
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
            
            QVector<Pecinha>
            agregadas;

            QString
            cor;

            void
            desenha();
    };
}

#endif // PECA_H
