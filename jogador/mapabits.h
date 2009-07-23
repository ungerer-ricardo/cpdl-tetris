#ifndef MAPABITS_H
#define MAPABITS_H

#include <QVector>

#include "pecinha.h"

namespace Tabuleiro
{
    class MapaBits
    {
        public:
            MapaBits( unsigned short int, unsigned short int );

            virtual
            ~MapaBits( );

            bool
            possoColocarAqui( Tabuleiro::TipoPeca, Tabuleiro::CoordenadaMapaBits );

        protected:

            /*
             * mapa[coluna][linha]
             */
            QVector< QVector<Tabuleiro::Pecinha*> >
            mapa;

            void
            defineTamanho( unsigned short int, unsigned short int );
    };
}

#endif // MAPABITS_H
