/********************************************************************************
** Form generated from reading ui file 'tabuleiro.ui'
**
** Created: Thu Aug 27 21:31:20 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TABULEIRO_H
#define UI_TABULEIRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tabuleiro
{
public:
    QWidget *piecesContainer;
    QLCDNumber *pontuacao;
    QLabel *labelPontuacao;
    QWidget *piecePreview;
    QLabel *labelPiecePreview;
    QLabel *labelLevel;
    QLCDNumber *level;

    void setupUi(QWidget *Tabuleiro)
    {
        if (Tabuleiro->objectName().isEmpty())
            Tabuleiro->setObjectName(QString::fromUtf8("Tabuleiro"));
        Tabuleiro->resize(220, 640);
        Tabuleiro->setMinimumSize(QSize(220, 640));
        Tabuleiro->setMaximumSize(QSize(220, 640));
        piecesContainer = new QWidget(Tabuleiro);
        piecesContainer->setObjectName(QString::fromUtf8("piecesContainer"));
        piecesContainer->setGeometry(QRect(10, 10, 200, 500));
        piecesContainer->setMaximumSize(QSize(200, 500));
        piecesContainer->setAutoFillBackground(true);
        piecesContainer->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 0);"));
        pontuacao = new QLCDNumber(Tabuleiro);
        pontuacao->setObjectName(QString::fromUtf8("pontuacao"));
        pontuacao->setGeometry(QRect(20, 600, 70, 30));
        pontuacao->setMaximumSize(QSize(70, 30));
        pontuacao->setMouseTracking(false);
        pontuacao->setAcceptDrops(false);
        pontuacao->setAutoFillBackground(false);
        pontuacao->setSegmentStyle(QLCDNumber::Flat);
        pontuacao->setProperty("intValue", QVariant(0));
        labelPontuacao = new QLabel(Tabuleiro);
        labelPontuacao->setObjectName(QString::fromUtf8("labelPontuacao"));
        labelPontuacao->setGeometry(QRect(20, 580, 70, 16));
        labelPontuacao->setTextFormat(Qt::AutoText);
        labelPontuacao->setScaledContents(false);
        piecePreview = new QWidget(Tabuleiro);
        piecePreview->setObjectName(QString::fromUtf8("piecePreview"));
        piecePreview->setEnabled(true);
        piecePreview->setGeometry(QRect(120, 540, 90, 90));
        piecePreview->setMaximumSize(QSize(90, 90));
        piecePreview->setAutoFillBackground(false);
        piecePreview->setStyleSheet(QString::fromUtf8("border-color: rgba(0, 0, 0, 0);"));
        labelPiecePreview = new QLabel(Tabuleiro);
        labelPiecePreview->setObjectName(QString::fromUtf8("labelPiecePreview"));
        labelPiecePreview->setGeometry(QRect(120, 520, 91, 16));
        labelPiecePreview->setTextFormat(Qt::AutoText);
        labelPiecePreview->setScaledContents(false);
        labelLevel = new QLabel(Tabuleiro);
        labelLevel->setObjectName(QString::fromUtf8("labelLevel"));
        labelLevel->setGeometry(QRect(20, 520, 70, 16));
        labelLevel->setTextFormat(Qt::AutoText);
        labelLevel->setScaledContents(false);
        level = new QLCDNumber(Tabuleiro);
        level->setObjectName(QString::fromUtf8("level"));
        level->setGeometry(QRect(20, 540, 70, 30));
        level->setMaximumSize(QSize(70, 30));
        level->setMouseTracking(false);
        level->setAcceptDrops(false);
        level->setAutoFillBackground(false);
        level->setSegmentStyle(QLCDNumber::Flat);
        level->setProperty("intValue", QVariant(0));

        retranslateUi(Tabuleiro);

        QMetaObject::connectSlotsByName(Tabuleiro);
    } // setupUi

    void retranslateUi(QWidget *Tabuleiro)
    {
        Tabuleiro->setWindowTitle(QApplication::translate("Tabuleiro", "Tabuleiro", 0, QApplication::UnicodeUTF8));
        labelPontuacao->setText(QApplication::translate("Tabuleiro", "Pontua\303\247\303\243o:", 0, QApplication::UnicodeUTF8));
        labelPiecePreview->setText(QApplication::translate("Tabuleiro", "Proxima pe\303\247a:", 0, QApplication::UnicodeUTF8));
        labelLevel->setText(QApplication::translate("Tabuleiro", "Level:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Tabuleiro);
    } // retranslateUi

};

namespace Ui {
    class Tabuleiro: public Ui_Tabuleiro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABULEIRO_H
