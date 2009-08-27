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
    this->timer2->disconnect( this->currentPiece, SLOT(rotaciona()) );
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

    this->caralho = new QRadioButton( this->ui->piecesContainer );
    QPalette
    pal;

    this->caralho->resize( Tab::P_SIZE );
    this->caralho->setEnabled(false);

    pal.setColor(QPalette::Button, "black");
    this->caralho->setPalette(pal);

    this->caralho->move( 60, 200 );
    this->caralho->show();

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

    qDebug() << "    Movendo controle da peca corrente para o MapaDeBits...";
//    this->timer->disconnect(this->currentPiece);

    qDebug() << "    Movendo a previsualizacao da peca para a peca corrente...";


    qDebug() << "    Instanciando nova previsualizacao...";
    //this->previewPiece = new Tab::Pivo( nova, QColor(0,0,0), pos, this->ui->piecePreview );

    qDebug() << "Conectando Signal do timer...";
//    connect(this->timer, SIGNAL(timeout()), this->currentPiece, SLOT(desce()));
//    this->timer->start(1000);
}
