#ifndef CLIENTE_H
#define CLIENTE_H

#include <QtGui/QDialog>
#include <QVector>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "chat.h"
#include "tabuleiro.h"

namespace Ui
{
    class Cliente;
}

class Cliente : public QDialog
{
    Q_OBJECT


    signals:
            //void signal_game_over();
            //void signal_game_over();

            void signal_move_peca(QString);

            void signal_rede_connect(QString);



public:
    Cliente(QWidget *parent = 0);
    ~Cliente();

    public slots:
        //chat
        void slot_chat_send_chat(QString);
        void slot_chat_recv_chat(QString);

        //tabuleiro
        void slot_tabu_move_peca(QString);
        void slot_tabu_nova_peca(QString);
        void slot_tabu_nova_peca(QString);

        //rede
        void slot_rede_move_peca(QInt, QString);



private:
    Ui::Cliente *ui;
    Chat * chat;
    QVector <Tabuleiro *> tabuleiros_vector;
    void addTabuleiro(Tabuleiro *);
    QHBoxLayout * hbox_layout;
    QVBoxLayout * vbox_layout;
};

#endif // CLIENTE_H
