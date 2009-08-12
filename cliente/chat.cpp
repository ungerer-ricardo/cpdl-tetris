#include "chat.h"

Chat::Chat(QWidget * parent) : QWidget(parent)
{
    this->line_edit = new QLineEdit();
    this->list_widget = new QListWidget();
    this->button_send = new QPushButton("Enviar Msg");

    this->hbox_layout = new QHBoxLayout();
    this->hbox_layout->addWidget(line_edit);
    this->hbox_layout->addWidget(button_send);

    this->vbox_layout = new QVBoxLayout(this);
    this->vbox_layout->addWidget(this->list_widget);
    this->vbox_layout->addLayout(this->hbox_layout);

    this->setupUi(this);

    QObject::connect(this->button_send,SIGNAL(clicked()),this,SLOT(slot_button_send_click()));
}

void Chat::setupUi(QWidget * parent) {

}

void Chat::slot_button_send_click() {
    emit this->send_chat(this->line_edit->text());    
    this->line_edit->clear();
}

void Chat::slot_new_message(QString mensagem) {
    this->list_widget->addItem(mensagem);
}
