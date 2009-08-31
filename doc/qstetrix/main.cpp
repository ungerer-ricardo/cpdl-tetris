#include "tetrixboard.h"

#include <QtGui>
#include <QtScript>
#include <QUiLoader>

#ifndef QT_NO_SCRIPTTOOLS
#include <QtScriptTools>
#endif

struct QtMetaObject : private QObject
{
public:
    static const QMetaObject *get()
        { return &static_cast<QtMetaObject*>(0)->staticQtMetaObject; }
};

//! [0]
class TetrixUiLoader : public QUiLoader
{
public:
    TetrixUiLoader(QObject *parent = 0)
        : QUiLoader(parent)
        { }
    virtual QWidget *createWidget(const QString &className, QWidget *parent = 0,
                                  const QString &name = QString())
    {
        if (className == QLatin1String("TetrixBoard")) {
            QWidget *board = new TetrixBoard(parent);
            board->setObjectName(name);
            return board;
        }
        return QUiLoader::createWidget(className, parent, name);
    }
};
//! [0]

static QScriptValue evaluateFile(QScriptEngine &engine, const QString &fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    return engine.evaluate(file.readAll(), fileName);
}

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(tetrix);

//! [1]
    QApplication app(argc, argv);
    QScriptEngine engine;

    QScriptValue Qt = engine.newQMetaObject(QtMetaObject::get());
    Qt.setProperty("App", engine.newQObject(&app));
    engine.globalObject().setProperty("Qt", Qt);
//! [1]

#ifndef QT_NO_SCRIPTTOOLS
    QScriptEngineDebugger debugger;
    debugger.attachTo(&engine);
    QMainWindow *debugWindow = debugger.standardWindow();
    debugWindow->resize(1024, 640);
#endif

//! [2]
    evaluateFile(engine, ":/tetrixpiece.js");
    evaluateFile(engine, ":/tetrixboard.js");
    evaluateFile(engine, ":/tetrixwindow.js");
//! [2]

//! [3]
    TetrixUiLoader loader;
    QFile uiFile(":/tetrixwindow.ui");
    uiFile.open(QIODevice::ReadOnly);
    QWidget *ui = loader.load(&uiFile);
    uiFile.close();

    QScriptValue ctor = engine.evaluate("TetrixWindow");
    QScriptValue scriptUi = engine.newQObject(ui, QScriptEngine::ScriptOwnership);
    QScriptValue tetrix = ctor.construct(QScriptValueList() << scriptUi);
//! [3]

    QPushButton *debugButton = qFindChild<QPushButton*>(ui, "debugButton");
#ifndef QT_NO_SCRIPTTOOLS
    QObject::connect(debugButton, SIGNAL(clicked()),
                     debugger.action(QScriptEngineDebugger::InterruptAction),
                     SIGNAL(triggered()));
    QObject::connect(debugButton, SIGNAL(clicked()),
                     debugWindow, SLOT(show()));
#else
    debugButton->hide();
#endif

//! [4]
    ui->resize(550, 370);
    ui->show();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return app.exec();
//! [4]
}
