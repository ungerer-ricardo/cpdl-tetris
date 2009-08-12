#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class Chat : public QWidget
{
    Q_OBJECT

    signals:
        void send_chat(QString);


public:
    Chat(QWidget * = NULL);

    public slots:
        void slot_button_send_click();
        void slot_new_message(QString);

private:
    QLineEdit * line_edit;
    QListWidget * list_widget;
    QVBoxLayout * vbox_layout;
    QHBoxLayout * hbox_layout;
    QPushButton * button_send;
    void setupUi(QWidget * = NULL);    


};




#endif // CHAT_H
