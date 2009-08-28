#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QVector>
#include <QWidget>

#include "../tabuleiro/tabuleiro.h"
#include "../rede_cliente/tradutor.h"

namespace Ui
{
    class JanelaPrincipal;
}

class JanelaPrincipal : public QWidget
{
    Q_OBJECT
public:
    JanelaPrincipal( QWidget* = NULL);

    virtual
    ~JanelaPrincipal();

public slots:

    void
    connectSuccess();

    void
    enviaMensagem();

    void
    startJogo();

private:

    QVector<Tabuleiro*>
    tabuleiros;

    Ui::JanelaPrincipal*
    janela;

    Rede_Cliente::Tradutor*
    rede;

    void
    keyPressEvent(QKeyEvent*);

};

#endif // JANELAPRINCIPAL_H
