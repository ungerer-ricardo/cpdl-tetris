/********************************************************************************
** Form generated from reading ui file 'JanelaPrincipal.ui'
**
** Created: Thu Aug 27 21:54:57 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *tabuleiros_layout;
    QWidget *layoutWidget;
    QVBoxLayout *chat_group;
    QListWidget *lista_chat;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *input_chat;

    void setupUi(QWidget *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName(QString::fromUtf8("JanelaPrincipal"));
        JanelaPrincipal->setWindowModality(Qt::ApplicationModal);
        JanelaPrincipal->resize(636, 878);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JanelaPrincipal->sizePolicy().hasHeightForWidth());
        JanelaPrincipal->setSizePolicy(sizePolicy);
        horizontalLayoutWidget = new QWidget(JanelaPrincipal);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 20, 401, 642));
        tabuleiros_layout = new QHBoxLayout(horizontalLayoutWidget);
        tabuleiros_layout->setObjectName(QString::fromUtf8("tabuleiros_layout"));
        tabuleiros_layout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(JanelaPrincipal);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 670, 593, 191));
        chat_group = new QVBoxLayout(layoutWidget);
        chat_group->setObjectName(QString::fromUtf8("chat_group"));
        chat_group->setContentsMargins(0, 0, 0, 0);
        lista_chat = new QListWidget(layoutWidget);
        lista_chat->setObjectName(QString::fromUtf8("lista_chat"));
        lista_chat->setMinimumSize(QSize(591, 141));

        chat_group->addWidget(lista_chat);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(71, 0));

        horizontalLayout->addWidget(label);

        input_chat = new QLineEdit(layoutWidget);
        input_chat->setObjectName(QString::fromUtf8("input_chat"));
        input_chat->setEnabled(false);

        horizontalLayout->addWidget(input_chat);


        chat_group->addLayout(horizontalLayout);


        retranslateUi(JanelaPrincipal);

        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QWidget *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QApplication::translate("JanelaPrincipal", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JanelaPrincipal", "Mensagem", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(JanelaPrincipal);
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
