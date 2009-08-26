#include "mapapecas.h"
#include <QDebug>

Tab::MapaPecas*
Tab::MapaPecas::instancia = 0;

Tab::MapaPecas*
Tab::MapaPecas::MeDaOMapa( )
{
    if( MapaPecas::instancia == NULL )
    {
        MapaPecas::instancia = new MapaPecas( );
    }

    return MapaPecas::instancia;
}

const Tab::TipoPeca
Tab::MapaPecas::operator[]( const int _id )
{
    return this->ComoEhAPeca( _id );
}

const Tab::TipoPeca
Tab::MapaPecas::ComoEhAPeca( const int _id )
{
    return this->pecas[_id];
}

Tab::MapaPecas::MapaPecas( )
{
    this->populaMapa( );
}

Tab::MapaPecas::~MapaPecas( )
{
}

void
Tab::MapaPecas::populaMapa( )
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

Tab::TipoPeca
Tab::MapaPecas::criaPecaVazia( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(0,0);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(0,0);

    return peca;
}

Tab::TipoPeca
Tab::MapaPecas::criaPecaZ( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(-1,0);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(0,-1);
    peca << Tab::Xy(-1,1);

    return peca;
}

Tab::TipoPeca
Tab::MapaPecas::criaPecaS( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(0,-1);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(1,0);
    peca << Tab::Xy(1,1);

    return peca;
}

Tab::TipoPeca
Tab::MapaPecas::criaPecaLinha( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(0,-1);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(0,1);
    peca << Tab::Xy(0,2);

    return peca;
}

Tab::TipoPeca
Tab::MapaPecas::criaPecaT( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(-1,0);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(1,0);
    peca << Tab::Xy(0,1);

    return peca;
}

Tab::TipoPeca
Tab::MapaPecas::criaPecaQuadrado( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(0,0);
    peca << Tab::Xy(1,0);
    peca << Tab::Xy(0,1);
    peca << Tab::Xy(1,1);

    return peca;
}

Tab::TipoPeca
Tab::MapaPecas::criaPecaL( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(-1,-1);
    peca << Tab::Xy(0,-1);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(0,1);

    return peca;
}

Tab::TipoPeca
Tab::MapaPecas::criaPecaJ( )
{
    Tab::TipoPeca
    peca;

    peca << Tab::Xy(1,-1);
    peca << Tab::Xy(0,-1);
    peca << Tab::Xy(0,0);
    peca << Tab::Xy(0,1);

    return peca;
}
