#include "pecinha.h"
#include <QDebug>

Tabuleiro::Pecinha::Pecinha( QColor _cor,
                             Tabuleiro::XyView _exibicaoPivo,
                             QWidget* _parent,
                             Tabuleiro::Xy const* _posicaoRelativa ) : QPushButton( _parent )
{
    QPalette
    pal;

    this->posicaoRelativa = _posicaoRelativa;
    this->setText( " " );
    this->resize( Tabuleiro::P_SIZE );
    this->setEnabled(false);

    pal.setColor(QPalette::Button, _cor);
    this->setPalette(pal);

    this->move( _exibicaoPivo );
    this->moveEu( _exibicaoPivo );

    this->show();
}

void
Tabuleiro::Pecinha::moveEu( Tabuleiro::XyView _posicaoPivo )
{
    if( this->posicaoRelativa != NULL )
    {
        this->move( this->calculaNovaPosicao(_posicaoPivo) );
    }
}

Tabuleiro::XyView
Tabuleiro::Pecinha::calculaNovaPosicao( Tabuleiro::XyView _posicaoPivo )
{
    Tabuleiro::XyView
    novaPosicao;

    novaPosicao.setX( _posicaoPivo.x() + (this->posicaoRelativa->first*Tabuleiro::P_SIZE.height()) );
    novaPosicao.setY( _posicaoPivo.y() + (this->posicaoRelativa->second*Tabuleiro::P_SIZE.width()) );

//    qDebug() << _posicaoPivo;
//    qDebug() << *this->posicaoRelativa;
//    qDebug() << novaPosicao << "\n";

    return novaPosicao;
}
