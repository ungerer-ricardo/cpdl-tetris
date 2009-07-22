#include "peca.h"


Tabuleiro::Peca::Peca(qint8 _idPeca, QWidget* _parent) : QWidget::QWidget(_parent)
{
    this->peca = Tabuleiro::MapaPecas::MeDaOMapa( )->ComoEhAPeca( _idPeca );

    this->tipoPecaInt = _idPeca;
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
