#include "pivo.h"
#include <QDebug>
#include <QMetaObject>

Tab::Pivo::Pivo( qint8 _idPeca, QColor _cor, Tab::XyView _posicaoTabuleiro, QWidget* _parent ) : Pecinha( _cor, _posicaoTabuleiro, _parent )
{
    this->peca = Tab::MapaPecas::MeDaOMapa( )->ComoEhAPeca( _idPeca );
    this->tipoPecaInt = _idPeca;
    this->visualizacao->move(_posicaoTabuleiro);
    this->cor = _cor;

    if( this->tipoPecaInt != 0 )
    {
        this->configuraAgregados( );
    }

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

    Tab::Xy
    iterador;
    
    qint8
    xVelho;

    qDebug() << "    Rotacionando peca...";

    if( ! (this->tipoPecaInt == 0 || this->tipoPecaInt == 5) )
    {
        foreach( iterador, this->peca )
        {
            novasPosicoes << Xy( iterador.second, -iterador.first );
        }

        if( this->possoColocarAqui(novasPosicoes, this->visualizacao->pos()) )
        {
            for( coordenadaPecinha = this->peca.begin(); coordenadaPecinha != this->peca.end(); ++coordenadaPecinha )
            {
                xVelho = coordenadaPecinha->first;
                coordenadaPecinha->first = coordenadaPecinha->second;
                coordenadaPecinha->second = -xVelho;
            }

            emit this->mudou(this->visualizacao->pos());
        }
        else
        {
            emit this->colidiu( );
        }
    }
}

void
Tab::Pivo::moveDireita( )
{
    qDebug() << "    Movendo peca para a direita...";
    this->visualizacao->move(this->visualizacao->x()+Tab::P_SIZE.height(), this->visualizacao->y()+Tab::P_SIZE.height());
    qDebug() << this->peca;
};

void
Tab::Pivo::moveEsquerda( )
{
    qDebug() << "    Movendo peca para a esquerda...";
    this->visualizacao->move(this->visualizacao->x()-Tab::P_SIZE.width(), this->visualizacao->y());
    qDebug() << this->peca;
};

void
Tab::Pivo::desce( )
{
    Tab::XyView
    novaPosicaoPivo = this->visualizacao->pos( );

    qDebug() << "Signal do timer recebido...";
    qDebug() << "    Descendo peca...";

    novaPosicaoPivo.ry() += Tab::P_SIZE.height();

    if( this->possoColocarAqui(this->peca, novaPosicaoPivo) )
    {
        this->visualizacao->move(this->visualizacao->x(), this->visualizacao->y()+Tab::P_SIZE.height());

        emit this->mudou(this->visualizacao->pos());
    }
    else
    {
        emit this->colidiu( );
    }
};

bool
Tab::Pivo::possoColocarAqui( Tab::TipoPeca _novasPosicoes, Tab::XyView _posicaoRealPivo )
{
    QWidget*
    objeto;

    Tab::XyView
    posicaoAVerificar;

    Tab::TipoPeca::iterator
    posicao;

    for( posicao = _novasPosicoes.begin(); posicao != _novasPosicoes.end(); ++posicao )
    {
        posicaoAVerificar.setX( (_posicaoRealPivo.x() + (posicao->first*Tab::P_SIZE.width())) );
        posicaoAVerificar.setY( (_posicaoRealPivo.y() + (posicao->second*Tab::P_SIZE.height())) );

        objeto = this->parentWidget()->childAt( posicaoAVerificar );

        if( (
                (objeto != 0) &&
                (objeto != this->agregadas[0]->getVisualizacao()) &&
                (objeto != this->agregadas[1]->getVisualizacao()) &&
                (objeto != this->agregadas[2]->getVisualizacao()) &&
                (objeto != this->visualizacao)
            ) ||
            (
                (posicaoAVerificar.x() < 0) ||
                (posicaoAVerificar.x() > 180)
            ) ||
            (
                (posicaoAVerificar.y() > 480)
            )
          )
        {
            return false;
        }
//        qDebug() << "OBJETO: " << objeto << " AGREGADA: " << this->agregadas[0]->getVisualizacao();
//        qDebug() << "OBJETO: " << objeto << " AGREGADA: " << this->agregadas[1]->getVisualizacao();
//        qDebug() << "OBJETO: " << objeto << " AGREGADA: " << this->agregadas[2]->getVisualizacao();
//        qDebug() << "OBJETO: " << objeto << " AGREGADA: " << this->visualizacao;
    }

    return true;
}


















