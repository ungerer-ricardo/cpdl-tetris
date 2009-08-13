#ifndef TIPOPECA_H
#define TIPOPECA_H

#include <QPair>
#include <QVector>
#include <QSize>

#include "basicos.h"

namespace Tabuleiro
{
    class MapaPecas
    {
        public:
            static MapaPecas*
            MeDaOMapa( );

            const Tabuleiro::TipoPeca
            ComoEhAPeca( const int );

            const Tabuleiro::TipoPeca
            operator[]( const int );

        protected:
            MapaPecas( );

            MapaPecas&
            operator=( MapaPecas const& );

            virtual
            ~MapaPecas( );

        private:
            static MapaPecas*
            instancia;

            QVector<Tabuleiro::TipoPeca>
            pecas;

            void
            populaMapa( );

            Tabuleiro::TipoPeca
            criaPecaVazia( );

            Tabuleiro::TipoPeca
            criaPecaZ( );

            Tabuleiro::TipoPeca
            criaPecaS( );

            Tabuleiro::TipoPeca
            criaPecaLinha( );

            Tabuleiro::TipoPeca
            criaPecaT( );

            Tabuleiro::TipoPeca
            criaPecaQuadrado( );

            Tabuleiro::TipoPeca
            criaPecaL( );

            Tabuleiro::TipoPeca
            criaPecaJ( );
    };
}

#endif // TIPOPECA_H
