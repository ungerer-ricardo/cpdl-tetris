#include "pivo.h"


Tabuleiro::Pivo::Pivo(qint8 _idPeca, QString _cor) : Pecinha(_cor)
{
    this->peca = Tabuleiro::MapaPecas::MeDaOMapa( )->ComoEhAPeca( _idPeca );

    this->tipoPecaInt = _idPeca;

    if( this->tipoPecaInt == 0 )
    {
        this->configuraAgregados( );
    }
}

void
Tabuleiro::Pivo::configuraAgregados( )
{
    Tabuleiro::Xy
    coordenadaPecinha;

    foreach( coordenadaPecinha, this->peca )
    {
        if( (coordenadaPecinha.first != 0) && (coordenadaPecinha.second != 0) )
        {
            this->agregadas << new Tabuleiro::Pecinha( this->cor, this, &coordenadaPecinha );
        }
    }
}

/*
 * @REFACTOR
 * tem q retornar a nova posicao
 */
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
