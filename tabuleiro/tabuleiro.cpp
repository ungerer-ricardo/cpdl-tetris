#include <QDebug>

#include "tabuleiro.h"
#include "ui_tabuleiro.h"

Tabuleiro::Tabuleiro(QWidget *parent)
    : QWidget(parent), ui(new Ui::Tabuleiro)
{
    qDebug() << "Configurando Ui...";
    ui->setupUi(this);

    qDebug() << "Conectando Signal do timer...";
    this->timer = new QTimer(this);
}

Tabuleiro::~Tabuleiro()
{
    delete ui;
}


void
Tabuleiro::rotacionapeca( )
{
    this->currentPiece->rotaciona();
}

void
Tabuleiro::movepeca( bool _direcao )
{
    qDebug() << "Signal para mover recebido...";
    if( _direcao )
    {
        this->currentPiece->moveDireita();
    }
    else
    {
        this->currentPiece->moveEsquerda();
    }
}

void
Tabuleiro::startjogo( qint8 descendo, qint8 proxima )
{
    qDebug() << "Signal para iniciar jogo recebido...";

    Tab::XyView
    pos(60,60);

    Tab::XyView
    pos1(30,30);

//    qDebug() << "    Instanciando Peca...";
//    this->currentPiece = new Tab::Pivo( descendo, QColor(0,0,0), pos, this->ui->piecesContainer );

    qDebug() << "    Instanciando Preview...";
    this->previewPiece = new Tab::Pivo( proxima, QColor(0,0,0), pos1, this->ui->piecePreview );

//    connect(this->timer, SIGNAL(timeout()), this->currentPiece, SLOT(desce()));
//    this->timer->start(1000);
}

void
Tabuleiro::novapeca( qint8 nova )
{
    qDebug() << "Signal de nova peca recebido...";

    Tab::XyView
    pos(30,30);

    qDebug() << "    Movendo controle da peca corrente para o MapaDeBits...";
//    this->timer->disconnect(this->currentPiece);

    qDebug() << "    Movendo a previsualizacao da peca para a peca corrente...";

    this->currentPiece->setParent( this->ui->piecesContainer );
    this->currentPiece->seta( this->ui->piecesContainer );


    qDebug() << "    Instanciando nova previsualizacao...";
    //this->previewPiece = new Tab::Pivo( nova, QColor(0,0,0), pos, this->ui->piecePreview );

    qDebug() << "Conectando Signal do timer...";
//    connect(this->timer, SIGNAL(timeout()), this->currentPiece, SLOT(desce()));
//    this->timer->start(1000);
}
