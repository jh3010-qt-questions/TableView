#include "modeldata.h"

//
// ModelList
//
ModelList::
ModelList( QObject* parent )
    : QAbstractTableModel (parent )
{
}



int
ModelList::
rowCount(const QModelIndex &) const
{
   int size = mList.size();

   return size;
}



int
ModelList::
columnCount( const QModelIndex & ) const
{
   return 2;
}




QVariant
ModelList::
data( const QModelIndex& index, int role ) const
{
    const ModelItem modelItem = mList.at( index.row() );

    QVariant result = QVariant();

    if ( role == Qt::DisplayRole )
    {
        if ( index.column() == 0 )
        {
          result = QVariant( QString( modelItem.population ) );
        }
        else
        {
          result = QVariant( QString::number( modelItem.averageAge ) );
        }
    }

    if ( role == int( ModelItem::Role::Selection ) )
    {
        result = QVariant( QString( modelItem.selected ? "#eeeeee" : "white" ) );
    }

    if ( role == int( ModelItem::Role::ColumnType ) )
    {
      if ( index.column() == 0 )
        result = QVariant( QString( "stringValue" ) );
      else
        result = QVariant( QString( "colorValue" ) );
    }

    if ( role == int( ModelItem::Role::ColorValue ) )
    {
      QString color;

      if ( modelItem.averageAge < 13 )
        color = "red";
      else if ( modelItem.averageAge < 35 )
        color = "yellow";
      else
        color = "green";

      result = QVariant( color );
    }

    qDebug() << role << " " << result;

    return result;
}



QVariant
ModelList::
headerData( int section, Qt::Orientation orientation, int role ) const
{
    if ( section == 0 )
        return QVariant( QString( "Population" ) );
    else
        return QVariant( QString( "Average Age" ) );
}



int
ModelList::
size() const
{
    return mList.size();
}



const QList<ModelItem>&
ModelList::
list() const
{
    return mList;
}



void
ModelList::
removeAt( int index )
{
    if ( index < 0 || index >= mList.size() )
        return;

    beginRemoveRows( QModelIndex(), index, index );
    mList.removeAt( index );
    endRemoveRows();

    emit sizeChanged();
}



void
ModelList::
add( const QString& population, const int averageAge )
{
    ModelItem item;

    item.population = population;
    item.averageAge = averageAge;

    add( item );
}



void
ModelList::
select( int index )
{
  beginResetModel();

  for ( int x = 0; x < this->mList.length(); x++ )
  {
    this->mList[x].selected = ( x == index );
  }

  endResetModel();
}




QHash<int, QByteArray>
ModelList::
roleNames() const
{
  return {
    { Qt::DisplayRole, "display" },
    { int( ModelItem::Role::Selection ), "selected" },
    { int( ModelItem::Role::ColumnType ), "type" },
    { int( ModelItem::Role::ColorValue ), "colorValue" }
  };

//  return this->mRoleNames;
}



void
ModelList::
add(const ModelItem& item)
{
    const int index = mList.size();

    beginInsertRows( QModelIndex(), index, index );
    mList.append( item );
    endInsertRows();

    emit sizeChanged();
}



void
ModelList::
reset()
{
    if ( mList.isEmpty() )
        return;

    beginRemoveRows( QModelIndex(), 0, mList.size() - 1 );
    mList.clear();
    endRemoveRows();

    emit sizeChanged();
}



//
// ModelResults
//
ModelResults::ModelResults(QObject* parent)
    : QObject(parent)
{
    mList = new ModelList( this );

    qRegisterMetaType<ModelItem>("ModelItem");
}



ModelList* ModelResults::list() const
{
    return mList;
}



void ModelResults::reset()
{
    mList->reset();
}
