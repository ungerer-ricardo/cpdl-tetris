#include "tipopeca.h"
#include <QDebug>

Tabuleiro::MapaPecas*
Tabuleiro::MapaPecas::instancia = 0;

Tabuleiro::MapaPecas*
Tabuleiro::MapaPecas::MeDaOMapa( )
{
    if( MapaPecas::instancia == NULL )
    {
        MapaPecas::instancia = new MapaPecas( );
    }

    return MapaPecas::instancia;
}

const Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::operator[]( const int _id )
{
    return this->ComoEhAPeca( _id );
}

const Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::ComoEhAPeca( const int _id )
{
    return this->pecas[_id];
}

Tabuleiro::MapaPecas::MapaPecas( )
{
    this->populaMapa( );
}

Tabuleiro::MapaPecas::~MapaPecas( )
{
}

void
Tabuleiro::MapaPecas::populaMapa( )
{
    this->pecas << this->criaPecaVazia( );
    this->pecas << this->criaPecaZ( );
    this->pecas << this->criaPecaS( );
    this->pecas << this->criaPecaLinha( );
    this->pecas << this->criaPecaT( );
    this->pecas << this->criaPecaQuadrado( );
    this->pecas << this->criaPecaL( );
    this->pecas << this->criaPecaJ( );
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaVazia( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(0,0);

    return peca;
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaZ( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(0,-1);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(-1,0);
    peca << Tabuleiro::Xy(-1,1);

    return peca;
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaS( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(0,-1);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(1,0);
    peca << Tabuleiro::Xy(1,1);

    return peca;
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaLinha( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(0,-1);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(0,1);
    peca << Tabuleiro::Xy(0,2);

    return peca;
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaT( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(-1,0);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(1,0);
    peca << Tabuleiro::Xy(0,1);

    return peca;
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaQuadrado( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(1,0);
    peca << Tabuleiro::Xy(0,1);
    peca << Tabuleiro::Xy(1,1);

    return peca;
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaL( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(-1,-1);
    peca << Tabuleiro::Xy(0,-1);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(0,1);

    return peca;
}

Tabuleiro::TipoPeca
Tabuleiro::MapaPecas::criaPecaJ( )
{
    Tabuleiro::TipoPeca
    peca;

    peca << Tabuleiro::Xy(1,-1);
    peca << Tabuleiro::Xy(0,-1);
    peca << Tabuleiro::Xy(0,0);
    peca << Tabuleiro::Xy(0,1);

    return peca;
}
