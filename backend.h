#ifndef BACKEND_H
#define BACKEND_H

#include <QQmlEngine>

#include <QJsonObject>
#include <QObject>
#include <QTimer>

#include "modeldata.h"


class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY( ModelResults* modelResults READ modelResults CONSTANT )

public:

    explicit Backend( QObject* parent = nullptr );

    static QObject* qmlSingletonInstance( QQmlEngine* engine, QJSEngine* scriptEngine )
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        return new Backend();
    }

    ModelResults* modelResults() const;

private:

    ModelResults* mModelResults;

    void createModelData();
};

#endif
