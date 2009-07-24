#ifndef PECINHA_H
#define PECINHA_H

//Falling Paradinhas
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>

#include <QStyle>
#include <QPalette>
#include <QColor>

#include "basicos.h"

namespace Tabuleiro
{
    class Pecinha : public QPushButton
    {
        public:
            Pecinha( QColor, Tabuleiro::XyView, QWidget* _parent, Tabuleiro::Xy const* = 0);

        public slots:
            void
            moveEu( Tabuleiro::XyView );

        protected:
            Tabuleiro::Xy const*
            posicaoRelativa;

            Tabuleiro::XyView
            calculaNovaPosicao( Tabuleiro::XyView );
    };
}

#endif // PECINHA_H
