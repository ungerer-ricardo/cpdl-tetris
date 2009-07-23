#ifndef PECINHA_H
#define PECINHA_H

//Falling Paradinhas
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>

#include "tipopeca.h"

namespace Tabuleiro
{
    class Pecinha : public QPushButton
    {
        public:
            Pecinha(QWidget* _parent = 0);

        private:
            Pecinha*
            pivo;

            Tabuleiro::TipoPeca*
            posicaoRelativa;
    };
}

#endif // PECINHA_H
