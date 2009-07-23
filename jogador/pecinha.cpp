#include "pecinha.h"

Tabuleiro::Pecinha::Pecinha(QWidget* _parent) : QPushButton(_parent)
{
    this->setText(" ");
    this->resize(Tabuleiro::P_SIZE);
}
