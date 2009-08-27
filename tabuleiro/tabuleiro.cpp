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

    connect(this, SIGNAL(keyPressed(int)), this, SLOT(onKeyPress(int)));
}

Tabuleiro::~Tabuleiro()
{
    delete ui;
}

void
Tabuleiro::onKeyPress( int _tecla )
{
    switch( _tecla )
    {
        case Qt::Key_Left:
                this->currentPiece->moveEsquerda();
            break;
        case Qt::Key_Down:
            this->currentPiece->desce();
            break;
        case Qt::Key_Right:
            this->currentPiece->moveDireita();
            break;
        case Qt::Key_Up:
            this->currentPiece->rotaciona();
            break;
    }
}

void
Tabuleiro::keyPressEvent( QKeyEvent* _evento )
{
    emit this->keyPressed( _evento->key() );
}

void
Tabuleiro::rotacionapeca( )
{
    qDebug() << "Signal para rotacionar recebido...";
    this->currentPiece->rotaciona();
}

void
Tabuleiro::colidiu( )
{
    qDebug() << "Signal de colisao recebido...";
    this->timer->disconnect( this->currentPiece, SLOT(desce()) );

    this->novapeca( (rand()%7)+1 );
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

    qDebug() << "    Instanciando Peca...";
    this->currentPiece = new Tab::Pivo( descendo, QColor("red"), pos, this->ui->piecesContainer );

    qDebug() << "    Instanciando Preview...";
    this->previewPiece = new Tab::Pivo( proxima, QColor(0,0,0), pos1, this->ui->piecePreview );

    connect(this->timer, SIGNAL(timeout()), this->currentPiece, SLOT(desce()));
    connect(this->currentPiece, SIGNAL(colidiu()), this, SLOT(colidiu()));
    this->timer->start(1000);

}

void
Tabuleiro::novapeca( qint8 nova )
{
    qDebug() << "Signal de nova peca recebido...";

    Tab::XyView
    pos(30,30);

    Tab::XyView
    pos1(60,60);

    qDebug() << "    Movendo a previsualizacao da peca para a peca corrente...";
    this->currentPiece = new Tab::Pivo( this->previewPiece->getPecaInt(), QColor("red"), pos1, this->ui->piecesContainer );

    qDebug() << "    Instanciando nova previsualizacao...";
    delete this->previewPiece;
    this->previewPiece = new Tab::Pivo( nova, QColor("red"), pos, this->ui->piecePreview );

    qDebug() << "Conectando Signal do timer...";
    connect(this->timer, SIGNAL(timeout()), this->currentPiece, SLOT(desce()));
    connect(this->currentPiece, SIGNAL(colidiu()), this, SLOT(colidiu()));
    this->timer->start(1000);
}
