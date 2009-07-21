#ifndef INTERFACECLIENTEREDE_H
#define INTERFACECLIENTEREDE_H

#include <QObject>

class InterfaceClienteRede : public QObject
{
    Q_OBJECT

    signals:
    	//cliente envia
	void queropeca();

    	//rede envia
    	void tomapeca( Peca , int jogador );

	//cliente envia
	void butao( Comando , int jogador );

	//cliente envia
	void enviamensagem( QString );

	//rede envia
	void recebemensagem( Mensagem );

	//rede envia
	void recebecomando( Comando );

	//cliente envia
	void gameover( int pontuacao );

	//rede envia
	void jogadorcaiu( int jogador );

	//rede envia
	void conexaobemsucedida( int total , int quemsoueu);

	//rede
	void novoplayer();

	//rede envia
	void start(Peca primeira, Peca segunda );
};

#endif // INTERFACECLIENTEREDE_H
