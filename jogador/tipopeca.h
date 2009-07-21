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

/*    class TipoPeca
    {
        QVector<peca>
        mapaPecas;
        
        TipoPeca( )
        {

            peca
            noShape = {(xy(0,0),    xy(0,0),    xy(0,0),    xy(0,0))};

            peca
            zShape = {xy(0,-1),   xy(0,0),    xy(-1,0),   xy(-1,1)};

            peca
            sShape = {xy(0,-1),   xy(0,0),    xy(1,0),    xy(1,1)};

            peca
            lineShape = {xy(0,-1),   xy(0,0),    xy(0,1),    xy(0,2)};

            peca
            tShape = {xy(-1,0),   xy(0,0),    xy(1,0),    xy(0,1)};

            peca
            squareShape = {xy(0,0),    xy(1,0),    xy(0,1),    xy(1,1)};

            peca
            lShape = {xy(-1,-1),  xy(0,-1),   xy(0,0),    xy(0,1)};

            peca
            mirroredLShape = {xy(1,-1),   xy(0,-1),   xy(0,0),    xy(0,1)};

        }
    }    */
}
#endif // TIPOPECA_H
