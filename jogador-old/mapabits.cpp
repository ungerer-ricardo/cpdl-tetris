#include "mapabits.h"

Tabuleiro::MapaBits::MapaBits( unsigned short int _tamanhoX, unsigned short int _tamanhoY )
{
    this->defineTamanho( _tamanhoX, _tamanhoY );
}

Tabuleiro::MapaBits::~MapaBits( )
{
}

void
Tabuleiro::MapaBits::defineTamanho( unsigned short int _tamanhoX, unsigned short int _tamanhoY )
{
    QVector<Tabuleiro::Pecinha*>
    iterador;

    this->mapa.resize( _tamanhoX );

    foreach( iterador, this->mapa )
    {
        iterador.resize( _tamanhoY );
    }
}

bool
Tabuleiro::MapaBits::possoColocarAqui( Tabuleiro::TipoPeca _coordenadasRelativas, Tabuleiro::CoordenadaMapaBits _posicaoPivo )
{
    bool
    pode;

    Tabuleiro::Xy
    pecinha;

    foreach( pecinha, _coordenadasRelativas )
    {
        pode = ( pode && this->temGenteAqui(_posicaoPivo.first+pecinha.first,_posicaoPivo.second+pecinha.second) );
    }

    return pode;
}

bool
Tabuleiro::MapaBits::temGenteAqui( unsigned int _x, unsigned int _y )
{
    return ( this->mapa[_x][_y] == NULL );
}
