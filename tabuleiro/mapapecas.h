#ifndef TIPOPECA_H
#define TIPOPECA_H

#include <QPair>
#include <QVector>
#include <QSize>

#include "basicos.h"

namespace Tab
{
    class MapaPecas
    {
        public:
            static MapaPecas*
            MeDaOMapa( );

            const Tab::TipoPeca
            ComoEhAPeca( const int );

            const Tab::TipoPeca
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

            QVector<Tab::TipoPeca>
            pecas;

            void
            populaMapa( );

            Tab::TipoPeca
            criaPecaVazia( );

            Tab::TipoPeca
            criaPecaZ( );

            Tab::TipoPeca
            criaPecaS( );

            Tab::TipoPeca
            criaPecaLinha( );

            Tab::TipoPeca
            criaPecaT( );

            Tab::TipoPeca
            criaPecaQuadrado( );

            Tab::TipoPeca
            criaPecaL( );

            Tab::TipoPeca
            criaPecaJ( );
    };
}

#endif // TIPOPECA_H
