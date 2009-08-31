#ifndef TETRIXBOARD_H
#define TETRIXBOARD_H

#include "server.h"
#include "client.h"

#include <QTimer>
#include <QFrame>
#include <QPointer>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class TetrixBoard : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QObject* timer READ getTimer)
    Q_PROPERTY(QWidget* nextPieceLabel WRITE setNextPieceLabel)

public:
    TetrixBoard(QWidget *parent = 0);

    void setNextPieceLabel(QWidget *label);
    void setBoardWidth(int width);
    void setBoardHeight(int height);
    QSize minimumSizeHint() const;

    QObject *getTimer();

signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);

#if !defined(Q_MOC_RUN)
private: // can only be emitted by TetrixBoard
#endif
    void keyPressed(int key);
    void paintRequested(QPainter *painter);
    void paintNextPieceRequested(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

protected slots:
    void showNextPiece(int width, int height);
    void drawPauseScreen(QPainter *painter);
    void drawSquare(QPainter *painter, int x, int y, int shape);
    void update();

private:
    TetrixServer server;

    enum { BoardWidth = 10, BoardHeight = 22 };

    int squareWidth() { return contentsRect().width() / BoardWidth; }
    int squareHeight() { return contentsRect().height() / BoardHeight; }

    QTimer *timer;
    QPointer<QLabel> nextPieceLabel;
    QImage image;
};

#endif
