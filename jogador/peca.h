#ifndef PECA_H
#define PECA_H

#include <QPair>
#include <QWidget>

#include "tipopeca.h"
#include "pecinha.h"


namespace Tabuleiro
{
    class Peca : public QWidget
    {
        Q_OBJECT

        public:
            Peca(qint8 = 0, QWidget* _parent = 0);
            
        public slots:
            void
            rotaciona();

            void
            desce();

        private:
            qint8
            tipoPecaInt;

            TipoPeca
            peca;
            
            QString
            cor;
            
            QVector<Pecinha>
            visualizacao;

            void
            desenha();
    };
}

#endif // PECA_H
