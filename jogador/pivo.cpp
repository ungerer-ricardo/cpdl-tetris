#include "pivo.h"
#include <QDebug>
#include <QMetaObject>

Tabuleiro::Pivo::Pivo( qint8 _idPeca, QColor _cor, Tabuleiro::XyView _posicaoTabuleiro, QWidget* _parent ) : Pecinha( _cor, _posicaoTabuleiro, _parent )
{
    this->peca = Tabuleiro::MapaPecas::MeDaOMapa( )->ComoEhAPeca( _idPeca );
    this->tipoPecaInt = _idPeca;

    if( this->tipoPecaInt != 0 )
    {
        this->configuraAgregados( );
    }

    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(desce()));
    this->timer->start(1000);


    this->timer2 = new QTimer(this);
    connect(this->timer2, SIGNAL(timeout()), this, SLOT(rotaciona()));
    this->timer2->start(500);
}

Tabuleiro::Pivo::~Pivo( )
{

}

void
Tabuleiro::Pivo::configuraAgregados( )
{
    Tabuleiro::TipoPeca::iterator
    coordenadaPecinha;

    for( coordenadaPecinha = this->peca.begin(); coordenadaPecinha != this->peca.end(); ++coordenadaPecinha )
    {
        if( ! (coordenadaPecinha->first == 0 && coordenadaPecinha->second == 0) )
        {
            this->agregadas << new Tabuleiro::Pecinha( this->cor, this->pos(), this->parentWidget(), coordenadaPecinha );
        }
    }

    connect(this, SIGNAL(mudou(Tabuleiro::XyView)), this->agregadas[0], SLOT(moveEu(Tabuleiro::XyView)));
    connect(this, SIGNAL(mudou(Tabuleiro::XyView)), this->agregadas[1], SLOT(moveEu(Tabuleiro::XyView)));
    connect(this, SIGNAL(mudou(Tabuleiro::XyView)), this->agregadas[2], SLOT(moveEu(Tabuleiro::XyView)));
}

void
Tabuleiro::Pivo::rotaciona( )
{
    Tabuleiro::TipoPeca::iterator
    coordenadaPecinha;

    Tabuleiro::TipoPeca
    novasPosicoes;
    
    qint8
    xVelho;

    if( ! (this->tipoPecaInt == 0 || this->tipoPecaInt == 5) )
    {
        for( coordenadaPecinha = this->peca.begin(); coordenadaPecinha != this->peca.end(); ++coordenadaPecinha )
        {
            xVelho = coordenadaPecinha->first;
            coordenadaPecinha->first = coordenadaPecinha->second;
            coordenadaPecinha->second = -xVelho;
//            novasPosicoes << Xy( coordenadaPecinha.second, -coordenadaPecinha.first );
        }
//            qDebug() << this->peca;
//        if( this->MapaBits->possoColocarAqui(novasPosicoes, this->ondeEuTo) )
//        {

        emit this->mudou(this->pos());
//        }
    }
}

void
Tabuleiro::Pivo::desce()
{
    this->move(this->x(), this->y()+Tabuleiro::P_SIZE.height());

    emit this->mudou(this->pos());
};

void
Tabuleiro::Pivo::desenha()
{

}
