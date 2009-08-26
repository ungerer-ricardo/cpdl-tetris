#include "pivo.h"
#include <QDebug>
#include <QMetaObject>

Tab::Pivo::Pivo( qint8 _idPeca, QColor _cor, Tab::XyView _posicaoTabuleiro, QWidget* _parent ) : Pecinha( _cor, _posicaoTabuleiro, _parent )
{
    this->peca = Tab::MapaPecas::MeDaOMapa( )->ComoEhAPeca( _idPeca );
    this->tipoPecaInt = _idPeca;
    this->visualizacao->move(_posicaoTabuleiro);

    if( this->tipoPecaInt != 0 )
    {
        this->configuraAgregados( );
    }

}

void
Tab::Pivo::seta (QWidget* _parent)
{
    this->agregadas[0]->setParent(_parent);
    this->agregadas[1]->setParent(_parent);
    this->agregadas[2]->setParent(_parent);
    this->setaPai(_parent);
}

Tab::Pivo::~Pivo( )
{
    this->visualizacao->hide();
}

void
Tab::Pivo::configuraAgregados( )
{
    Tab::TipoPeca::iterator
    coordenadaPecinha;

    for( coordenadaPecinha = this->peca.begin(); coordenadaPecinha != this->peca.end(); ++coordenadaPecinha )
    {
        if( ! (coordenadaPecinha->first == 0 && coordenadaPecinha->second == 0) )
        {
            this->agregadas << new Tab::Pecinha( this->cor, this->pos(), this->parentWidget(), coordenadaPecinha );
        }
    }

    connect(this, SIGNAL(mudou(Tab::XyView)), this->agregadas[0], SLOT(moveEu(Tab::XyView)));
    connect(this, SIGNAL(mudou(Tab::XyView)), this->agregadas[1], SLOT(moveEu(Tab::XyView)));
    connect(this, SIGNAL(mudou(Tab::XyView)), this->agregadas[2], SLOT(moveEu(Tab::XyView)));
}

void
Tab::Pivo::rotaciona( )
{
    Tab::TipoPeca::iterator
    coordenadaPecinha;

    Tab::TipoPeca
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

        emit this->mudou(this->visualizacao->pos());
//        }
    }
}

void
Tab::Pivo::moveDireita()
{
    qDebug() << "    Movendo peca para a direita...";
    this->visualizacao->move(this->visualizacao->x()+Tab::P_SIZE.height(), this->visualizacao->y()+Tab::P_SIZE.height());
    qDebug() << this->peca;
};

void
Tab::Pivo::moveEsquerda()
{
    qDebug() << "    Movendo peca para a esquerda...";
    this->visualizacao->move(this->visualizacao->x()-Tab::P_SIZE.width(), this->visualizacao->y());
    qDebug() << this->peca;
};

void
Tab::Pivo::desce()
{
    qDebug() << "Signal do timer recebido...";
    qDebug() << "    Descendo peca...";
    this->visualizacao->move(this->visualizacao->x(), this->visualizacao->y()+Tab::P_SIZE.height());
    qDebug() << this->peca;

    emit this->mudou(this->visualizacao->pos());
};

void
Tab::Pivo::desenha()
{

}
