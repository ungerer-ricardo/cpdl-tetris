#include "peca.h"


Tabuleiro::Peca::Peca(qint8 _idPeca, QWidget* _parent) : QWidget::QWidget(_parent)
{
    this->peca.push_back(Xy(0,-1));
    this->peca.push_back(Xy(0,0));
    this->peca.push_back(Xy(-1,0));
    this->peca.push_back(Xy(-1,1));

    this->tipoPecaInt = 2;
}

void
Tabuleiro::Peca::rotaciona()
{
    if( this->tipoPecaInt != 0 )
    {
        for( TipoPeca::iterator i = this->peca.begin(); i != this->peca.end(); ++i )
        {
            i->first = i->second;
            i->second = -i->first;
        }
    }
}

void
Tabuleiro::Peca::desce()
{

};

void
Tabuleiro::Peca::desenha()
{

}
