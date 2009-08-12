#include "cliente.h"
#include "ui_cliente.h"

Cliente::Cliente(QWidget *parent)
    : QDialog(parent), ui(new Ui::Cliente)
{


    hbox_layout = new QHBoxLayout();
    vbox_layout = new QVBoxLayout(this);

    chat = new Chat();
    Chat * chat2 = new Chat();

    //vbox_layout->addLayout(hbox_layout);

    Tabuleiro * tab1 = new Tabuleiro();
    Tabuleiro * tab2 = new Tabuleiro();
    Tabuleiro * tab3 = new Tabuleiro();
    Tabuleiro * tab4 = new Tabuleiro();

    hbox_layout->addWidget(tab1);
    hbox_layout->addWidget(tab2);
    hbox_layout->addWidget(tab3);
    hbox_layout->addWidget(tab4);

    vbox_layout->addLayout(hbox_layout);
    vbox_layout->addWidget(chat);

    //Tabuleiro * tab = new Tabuleiro(this);
    //this->addTabuleiro(tab);

    QObject::connect(this->chat,SIGNAL(send_chat(QString)),this,SLOT(slot_chat_send_chat(QString)));
    QObject::connect(this->chat,SIGNAL(slot_new_message(QString)),this,SLOT(slot_chat_recv_chat(QString)));

    ui->setupUi(this);
;
}

Cliente::~Cliente()
{
    delete ui;
}


void Cliente::addTabuleiro(Tabuleiro * tabuleiro) {
    //this->hbox_layout->addWidget(tabuleiro);
    //this->tabuleiros_vector.push_back(tabuleiro);
}

void Cliente::slot_chat_send_chat(QString mensagem) {
    qDebug() << "novo chat " << mensagem;
}
void Cliente::slot_chat_recv_chat(QString mensagem) {
    mensagem = "Lucas " + mensagem;

    emit this->chat->slot_new_message(mensagem);
}
