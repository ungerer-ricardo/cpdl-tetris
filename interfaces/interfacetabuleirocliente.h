#ifndef TABULEIROCLIENTE_H_
#define TABULEIROCLIENTE_H_

#include <QObject>

class TabuleiroCliente
{
	Q_OBJECT
signals:
	void encaixe( Peca );

	void rotacionapeca();

	//true -> direita
	//false -> esquerda
	void movepeca(bool _direcao);

	void startjogo( Peca descendo, Peca proxima);

	void gameover( int pontuacao );
}
 
#endif TABULEIROCLIENTE_H_
 
