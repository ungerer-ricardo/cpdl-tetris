#include "pivo.h"


Tabuleiro::Pivo::Pivo(qint8 _idPeca)
{
    this->peca = Tabuleiro::MapaPecas::MeDaOMapa( )->ComoEhAPeca( _idPeca );

    this->tipoPecaInt = _idPeca;
}

void
Tabuleiro::Pivo::rotaciona()
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
Tabuleiro::Pivo::desce()
{

};

void
Tabuleiro::Pivo::desenha()
{

}
