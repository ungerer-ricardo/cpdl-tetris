#include "janelaprincipal.h"

#include "ui_JanelaPrincipal.h"

JanelaPrincipal::JanelaPrincipal(QWidget* _parent) :
        QWidget(_parent),
        janela( new Ui::JanelaPrincipal())
{
    this->janela->setupUi(this);

    QObject::connect( this->janela->input_chat, SIGNAL(returnPressed()),
                      this, SLOT(enviaMensagem()));
}

void
enviaMensagem()
{


}
