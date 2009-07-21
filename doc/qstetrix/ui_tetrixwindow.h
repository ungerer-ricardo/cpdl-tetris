/********************************************************************************
** Form generated from reading ui file 'tetrixwindow.ui'
**
** Created: Mon May 11 12:39:25 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TETRIXWINDOW_H
#define UI_TETRIXWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "tetrixboard.h"

QT_BEGIN_NAMESPACE

class Ui_TetrixWindow
{
public:
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QLabel *nextLabel;
    TetrixBoard *board;
    QLabel *nextPieceLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    TetrixBoard *opBoard;
    QLabel *scoreLabel;
    QLCDNumber *scoreLcd;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *TetrixWindow)
    {
        if (TetrixWindow->objectName().isEmpty())
            TetrixWindow->setObjectName(QString::fromUtf8("TetrixWindow"));
        TetrixWindow->resize(741, 475);
        vboxLayout = new QVBoxLayout(TetrixWindow);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setMargin(9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setMargin(0);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nextLabel = new QLabel(TetrixWindow);
        nextLabel->setObjectName(QString::fromUtf8("nextLabel"));
        nextLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(nextLabel, 0, 0, 1, 1);

        board = new TetrixBoard(TetrixWindow);
        board->setObjectName(QString::fromUtf8("board"));
        board->setFocusPolicy(Qt::StrongFocus);
        board->setFrameShape(QFrame::Panel);
        board->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(board, 1, 1, 5, 1);

        nextPieceLabel = new QLabel(TetrixWindow);
        nextPieceLabel->setObjectName(QString::fromUtf8("nextPieceLabel"));
        nextPieceLabel->setFrameShape(QFrame::Box);
        nextPieceLabel->setFrameShadow(QFrame::Raised);
        nextPieceLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nextPieceLabel, 1, 0, 1, 1);

        startButton = new QPushButton(TetrixWindow);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(startButton, 4, 0, 1, 1);

        quitButton = new QPushButton(TetrixWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(quitButton, 5, 0, 1, 1);

        opBoard = new TetrixBoard(TetrixWindow);
        opBoard->setObjectName(QString::fromUtf8("opBoard"));
        opBoard->setFocusPolicy(Qt::StrongFocus);
        opBoard->setFrameShape(QFrame::Panel);
        opBoard->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(opBoard, 1, 2, 5, 1);

        scoreLabel = new QLabel(TetrixWindow);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(scoreLabel, 2, 0, 1, 1);

        scoreLcd = new QLCDNumber(TetrixWindow);
        scoreLcd->setObjectName(QString::fromUtf8("scoreLcd"));
        scoreLcd->setSegmentStyle(QLCDNumber::Filled);

        gridLayout->addWidget(scoreLcd, 3, 0, 1, 1);

        label_2 = new QLabel(TetrixWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(TetrixWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label, 0, 1, 1, 1);


        vboxLayout->addLayout(gridLayout);


        retranslateUi(TetrixWindow);

        QMetaObject::connectSlotsByName(TetrixWindow);
    } // setupUi

    void retranslateUi(QWidget *TetrixWindow)
    {
        TetrixWindow->setWindowTitle(QApplication::translate("TetrixWindow", "Tetrix", 0, QApplication::UnicodeUTF8));
        nextLabel->setText(QApplication::translate("TetrixWindow", "Pr\303\263ximo", 0, QApplication::UnicodeUTF8));
        nextPieceLabel->setText(QString());
        startButton->setText(QApplication::translate("TetrixWindow", "&Iniciar", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("TetrixWindow", "&Sair", 0, QApplication::UnicodeUTF8));
        scoreLabel->setText(QApplication::translate("TetrixWindow", "Pontua\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TetrixWindow", "Oponente", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TetrixWindow", "Voc\303\252", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TetrixWindow);
    } // retranslateUi

};

namespace Ui {
    class TetrixWindow: public Ui_TetrixWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIXWINDOW_H
