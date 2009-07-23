#include "pecinha.h"

Tabuleiro::Pecinha::Pecinha( QString _cor,
                             Tabuleiro::Pecinha* _pivo,
                             Tabuleiro::Xy const* _posicaoRelativa,
                             QWidget* _parent ) : QPushButton( _parent )
{
    this->setText( " " );
    this->resize( Tabuleiro::P_SIZE );
}
