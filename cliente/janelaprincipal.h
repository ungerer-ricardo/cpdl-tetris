#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QVector>
#include <QWidget>

#include "tabuleiro.h"

namespace Ui
{
    class JanelaPrincipal;
}

class JanelaPrincipal : public QWidget
{
public:
    JanelaPrincipal( QWidget* = NULL);

public slots:

    void
    enviaMensagem();

private:

    QVector<Tabuleiro*>
    tabuleiros;

    Ui::JanelaPrincipal*
    janela;
};

#endif // JANELAPRINCIPAL_H
