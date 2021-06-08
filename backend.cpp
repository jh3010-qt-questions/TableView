#include "backend.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

Backend::
Backend( QObject* parent )
    : QObject( parent )
{
    this->mModelResults = new ModelResults( this );

    createModelData();
}



ModelResults *
Backend::
modelResults() const
{
  return mModelResults;
}



void
Backend::
createModelData()
{
  this->mModelResults->list()->add( QString( "Pop A" ), 10 );
  this->mModelResults->list()->add( QString( "Pop B" ), 15 );
  this->mModelResults->list()->add( QString( "Pop C" ), 35 );
}


