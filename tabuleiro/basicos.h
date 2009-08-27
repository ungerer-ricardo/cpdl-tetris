#ifndef BASICOS_H
#define BASICOS_H

#include <QPoint>

namespace Tab
{
    typedef QPair<qint8, qint8>
    Xy;

    typedef QVector<Xy>
    TipoPeca;

    typedef unsigned int
    Pixel;

    typedef QPair<unsigned int, unsigned int>
    CoordenadaMapaBits;

    typedef QPoint
    XyView;

    const QSize
    P_SIZE(20,20);
}

#endif // BASICOS_H
