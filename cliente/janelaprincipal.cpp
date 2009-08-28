#include "janelaprincipal.h"

#include "ui_JanelaPrincipal.h"

JanelaPrincipal::JanelaPrincipal(QWidget* _parent) :
        QWidget(_parent),
        janela( new Ui::JanelaPrincipal())
{
    this->janela->setupUi(this);

    this->rede = new Rede_Cliente::Tradutor(this);

    this->rede->setConexao("192.168.1.101",6969);

    QObject::connect(this->rede, SIGNAL(connectSuccessSignal()),
                 this, SLOT(connectSuccess()));
}

JanelaPrincipal::~JanelaPrincipal()
{

}

void
JanelaPrincipal::connectSuccess()
{
    this->janela->input_chat->setEnabled(true);

    Tabuleiro*
    novo_tabuleiro = new Tabuleiro();

    this->tabuleiros.push_back(novo_tabuleiro);

    this->janela->tabuleiros_layout->addWidget(novo_tabuleiro);

    novo_tabuleiro->show();

    QObject::connect( this->rede, SIGNAL(startjogo(qint8,qint8)),
                  this->tabuleiros[0], SLOT(startjogo(qint8,qint8)));

    QObject::connect( this->rede, SIGNAL(button(int)),
                      this->tabuleiros[0], SLOT(onKeyPress(int)));

    QObject::connect( this->janela->input_chat, SIGNAL(returnPressed()),
                  this, SLOT(enviaMensagem()));

    QObject::connect( this->tabuleiros[0], SIGNAL(procuraLinhas()),
                      this->rede, SLOT(encaixe()));

    QObject::connect( this->rede, SIGNAL(novapeca(qint8)),
                      this->tabuleiros[0], SLOT(novapeca(qint8)));
}

void
JanelaPrincipal::enviaMensagem()
{
    QString
    mensagem = this->janela->input_chat->text();

    this->janela->input_chat->setText("");

    this->rede->chat(mensagem);
}

void
JanelaPrincipal::startJogo()
{

}


void
JanelaPrincipal::keyPressEvent(QKeyEvent* _event)
{
    switch( _event->key() )
    {
        case Qt::Key_Left:
            this->rede->movimentaEsquerda();
            break;
        case Qt::Key_Down:
            qDebug() << "num tah feito... vc não pode mover para baixo!";
            break;
        case Qt::Key_Right:
            this->rede->movimentaDireita();
            break;
        case Qt::Key_Up:
            this->rede->rotacao();
            break;
        case Qt::Key_Space:
            this->rede->encaixe();
            break;
    }

    _event->accept();
}

