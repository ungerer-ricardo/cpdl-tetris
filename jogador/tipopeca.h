#ifndef TIPOPECA_H
#define TIPOPECA_H

#include <QPair>
#include <QVector>

namespace Tabuleiro
{
    typedef QPair<qint8, qint8>
    Xy;

    typedef QVector<Xy>
    TipoPeca;

    class MapaPecas
    {
        public:
            static MapaPecas*
            MeDaOMapa( );

            const TipoPeca
            ComoEhAPeca( int );

        protected:
            MapaPecas( );

            MapaPecas&
            operator=( MapaPecas const& );

            virtual
            ~MapaPecas( );

        private:
            static MapaPecas*
            instancia;

            QVector<TipoPeca>
            pecas;

            void
            populaMapa( );

            TipoPeca
            criaPecaVazia( );

            TipoPeca
            criaPecaZ( );

            TipoPeca
            criaPecaS( );

            TipoPeca
            criaPecaLinha( );

            TipoPeca
            criaPecaT( );

            TipoPeca
            criaPecaQuadrado( );

            TipoPeca
            criaPecaL( );

            TipoPeca
            criaPecaJ( );
    };
}

#endif // TIPOPECA_H
