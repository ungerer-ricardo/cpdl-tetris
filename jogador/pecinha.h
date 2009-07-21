#ifndef PECINHA_H
#define PECINHA_H

//Falling Paradinhas
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>

namespace Tabuleiro
{
    class Pecinha : public QPushButton
    {
        public:
            Pecinha(QWidget* _parent = 0);
    };
}

#endif // PECINHA_H
