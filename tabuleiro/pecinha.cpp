#include "pecinha.h"
#include <QDebug>

Tab::Pecinha::Pecinha( QColor _cor,
                             Tab::XyView _exibicaoPivo,
                             QWidget* _parent,
                             Tab::Xy const* _posicaoRelativa ) : QWidget( _parent )
{
    this->visualizacao = new QPushButton( _parent );

    QPalette
    pal;

    this->posicaoRelativa = _posicaoRelativa;
    this->visualizacao->resize( Tab::P_SIZE );
    this->visualizacao->setEnabled(false);

    pal.setColor(QPalette::Button, _cor);
    this->visualizacao->setPalette(pal);

    this->move( _exibicaoPivo );
    this->moveEu( _exibicaoPivo );

    this->visualizacao->show();
}

Tab::Pecinha::~Pecinha( )
{
    delete this->visualizacao;
}

QWidget const*
Tab::Pecinha::getVisualizacao( )
{
    return this->visualizacao;
}

void
Tab::Pecinha::moveEu( Tab::XyView _posicaoPivo )
{
    if( this->posicaoRelativa != NULL )
    {
        this->visualizacao->move( this->calculaNovaPosicao(_posicaoPivo) );
    }
}

Tab::XyView
Tab::Pecinha::calculaNovaPosicao( Tab::XyView _posicaoPivo )
{
    Tab::XyView
    novaPosicao;

    novaPosicao.setX( _posicaoPivo.x() + (this->posicaoRelativa->first*Tab::P_SIZE.height()) );
    novaPosicao.setY( _posicaoPivo.y() + (this->posicaoRelativa->second*Tab::P_SIZE.width()) );

//    qDebug() << _posicaoPivo;
//    qDebug() << *this->posicaoRelativa;
//    qDebug() << novaPosicao << "\n";

    return novaPosicao;
}
