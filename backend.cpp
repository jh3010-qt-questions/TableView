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
  this->mModelResults->list()->add( QString( "Pop D" ), 47 );
  this->mModelResults->list()->add( QString( "Pop E" ), 14 );
  this->mModelResults->list()->add( QString( "Pop F" ), 76 );
  this->mModelResults->list()->add( QString( "Pop G" ), 13 );
  this->mModelResults->list()->add( QString( "Pop H" ), 65 );
  this->mModelResults->list()->add( QString( "Pop I" ), 83 );
  this->mModelResults->list()->add( QString( "Pop J" ), 16 );
  this->mModelResults->list()->add( QString( "Pop K" ), 62 );
  this->mModelResults->list()->add( QString( "Pop L" ), 87 );
  this->mModelResults->list()->add( QString( "Pop M" ), 39 );
  this->mModelResults->list()->add( QString( "Pop N" ), 75 );
  this->mModelResults->list()->add( QString( "Pop O" ), 14 );
  this->mModelResults->list()->add( QString( "Pop P" ), 26 );
  this->mModelResults->list()->add( QString( "Pop Q" ), 56 );
  this->mModelResults->list()->add( QString( "Pop R" ), 99 );
  this->mModelResults->list()->add( QString( "Pop S" ), 2 );
  this->mModelResults->list()->add( QString( "Pop T" ), 5 );
}


