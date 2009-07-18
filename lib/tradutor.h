#ifndef TRADUTOR_H
#define TRADUTOR_H

#include <QObject>

enum Comando
{


};

typedef struct
{
    int
    user;

    Comando
    comando;

    int
    parametro;

} ComandoParseado;

class Tradutor : public QObject
{
    Q_OBJECT
public:

    Tradutor( QObject* _parent = 0 );

    ComandoParseado
    traduzir( QByteArray _dado );
};

#endif // TRADUTOR_H
