#include "pivo.h"


Tabuleiro::Pivo::Pivo( qint8 _idPeca, QString _cor ) : Pecinha( _cor )
{
    this->peca = Tabuleiro::MapaPecas::MeDaOMapa( )->ComoEhAPeca( _idPeca );

    this->tipoPecaInt = _idPeca;

    if( this->tipoPecaInt == 0 )
    {
        this->configuraAgregados( );
    }
}

Tabuleiro::Pivo::~Pivo( )
{

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
Tabuleiro::Pivo::rotaciona( )
{
    Tabuleiro::Xy
    coordenadaPecinha;

    Tabuleiro::TipoPeca
    novasPosicoes;

    if( this->tipoPecaInt != 0 )
    {
        foreach( coordenadaPecinha, this->peca )
        {
            novasPosicoes << Xy( coordenadaPecinha.second, -coordenadaPecinha.first );
        }

//        if( this->MapaBits->possoColocarAqui(novasPosicoes, this->ondeEuTo) )
//        {
//            this->peca = novasPosicoes;
//        }
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
