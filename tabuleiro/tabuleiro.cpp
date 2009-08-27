#include <QDebug>
#include <QTime>

#include "tabuleiro.h"
#include "ui_tabuleiro.h"

Tabuleiro::Tabuleiro(QWidget *parent)
    : QWidget(parent), ui(new Ui::Tabuleiro)
{
    qDebug() << "Configurando Ui...";
    ui->setupUi(this);

    qDebug() << "Conectando Signal do timer...";

    this->timer = new QTimer(this);
    this->pontuacao = 0;
    this->level = 1;

    connect( this, SIGNAL(keyPressed(int)), this, SLOT(onKeyPress(int)) );
    connect( this, SIGNAL(linhaCheia(Tab::XyView)), this, SLOT(apagaLinhaCheia(Tab::XyView)) );
    connect( this, SIGNAL(procuraLinhas()), this, SLOT(procuraLinhasCheias()) );
    connect( this, SIGNAL(pontuacaoMudou()), this, SLOT(setPontuacao()) );
    connect( this, SIGNAL(levelMudou()), this, SLOT(setLevel()) );

    emit this->levelMudou( );
    emit this->pontuacaoMudou( );
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
        case Qt::Key_Space:
            this->pontuacao += this->currentPiece->desceTudo();
            emit this->pontuacaoMudou();
            break;
    }
}

void
Tabuleiro::keyPressEvent( QKeyEvent* _evento )
{
    emit this->keyPressed( _evento->key() );
}

void
Tabuleiro::procuraLinhasCheias( )
{
    QWidget*
    objeto;

    unsigned short int
    elementosNaLinha;

    Tab::XyView
    posicaoAVerificar;

    posicaoAVerificar.setY( (Tab::P_SIZE.height()*24) );

    while( posicaoAVerificar.y() >= 0 )
    {
        elementosNaLinha = 0;
        posicaoAVerificar.setX( 0 );

        while( posicaoAVerificar.x() <= (Tab::P_SIZE.width()*9) )
        {
            objeto = this->ui->piecesContainer->childAt( posicaoAVerificar );

            if( objeto != 0 )
            {
                ++elementosNaLinha;
            }
            posicaoAVerificar.rx() += Tab::P_SIZE.width();
        }

        if(elementosNaLinha == 10)
        {
            emit this->apagaLinhaCheia( posicaoAVerificar );
            posicaoAVerificar.setY( (Tab::P_SIZE.height()*24) );
        }
        else
        {
            posicaoAVerificar.ry() -= Tab::P_SIZE.height();
        }
    }
}

void
Tabuleiro::apagaLinhaCheia( Tab::XyView _posicaoAApagar )
{
    QWidget*
    objeto;

    _posicaoAApagar.setX( 0 );

    while( _posicaoAApagar.x() <= (Tab::P_SIZE.width()*9) )
    {
        objeto = this->ui->piecesContainer->childAt( _posicaoAApagar );

        delete objeto;

        _posicaoAApagar.rx() += Tab::P_SIZE.width();
    }

    this->pontuacao += 10;
    emit pontuacaoMudou();

    this->desceLinhas( _posicaoAApagar );
}

void
Tabuleiro::desceLinhas( Tab::XyView _posicao )
{
    QWidget*
    objeto;

    Tab::XyView
    novaPosicao;

    while( _posicao.y() >= 0 )
    {
        _posicao.setX( 0 );

        while( _posicao.x() <= (Tab::P_SIZE.width()*9) )
        {
            objeto = this->ui->piecesContainer->childAt( _posicao );

            if( objeto != 0 )
            {
                novaPosicao = _posicao;
                novaPosicao.ry() += Tab::P_SIZE.height();

                objeto->move( novaPosicao );
            }

            _posicao.rx() += Tab::P_SIZE.width();
        }

        _posicao.ry() -= Tab::P_SIZE.height();
    }
}

void
Tabuleiro::setLevel( )
{
    this->ui->level->display( (int) this->level );
}

void
Tabuleiro::setPontuacao( )
{
    this->ui->pontuacao->display( (int) this->pontuacao );
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

    emit this->procuraLinhas( );

    qsrand( QTime::currentTime().msec() );
    this->novapeca( (qrand() % 7) + 1 );
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
    this->currentPiece = new Tab::Pivo( descendo, QColor(0,0,0), pos, this->ui->piecesContainer );

    qDebug() << "    Instanciando Preview...";
    this->previewPiece = new Tab::Pivo( proxima, QColor(0,0,0), pos1, this->ui->piecePreview );

    connect( this->timer, SIGNAL(timeout()), this->currentPiece, SLOT(desce()) );
    connect( this->currentPiece, SIGNAL(colidiu()), this, SLOT(colidiu()) );

    this->timer->start( this->getTimeOut() );

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
    this->currentPiece = new Tab::Pivo( this->previewPiece->getPecaInt(), QColor(0,0,0), pos1, this->ui->piecesContainer );

    qDebug() << "    Instanciando nova previsualizacao...";
    delete this->previewPiece;
    this->previewPiece = new Tab::Pivo( nova, QColor(0,0,0), pos, this->ui->piecePreview );

    qDebug() << "Conectando Signal do timer...";
    connect(this->timer, SIGNAL(timeout()), this->currentPiece, SLOT(desce()));
    connect(this->currentPiece, SIGNAL(colidiu()), this, SLOT(colidiu()));

    this->timer->start( this->getTimeOut() );
}

unsigned int
Tabuleiro::getTimeOut( )
{
    return ( 2000 / (1+this->level) );
}
