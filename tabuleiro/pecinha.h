#ifndef PECINHA_H
#define PECINHA_H

//Falling Paradinhas
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QWidget>

#include <QStyle>
#include <QPalette>
#include <QColor>

#include "basicos.h"

namespace Tab
{
    class Pecinha : public QWidget
    {
        Q_OBJECT

        public:
            Pecinha( QColor, Tab::XyView, QWidget* _parent, Tab::Xy const* = 0);

            ~Pecinha( );

            QWidget const*
            getVisualizacao( );

        public slots:
            void
            moveEu( Tab::XyView );

        protected:
            Tab::Xy const*
            posicaoRelativa;

            Tab::XyView
            calculaNovaPosicao( Tab::XyView );

            QWidget*
            visualizacao;
    };
}

#endif // PECINHA_H
