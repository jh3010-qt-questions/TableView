#ifndef MODELDATA_H
#define MODELDATA_H

#include <QtQml>

#include <QAbstractTableModel>
#include <QObject>

//
// ModelItem
//
struct ModelItem
{
    Q_GADGET

    Q_PROPERTY( QString population MEMBER population )
    Q_PROPERTY( int averageAge MEMBER averageAge )
    Q_PROPERTY( bool selected MEMBER selected )

public:

    enum class Role {
      Selection = Qt::UserRole,
      ColumnType,
      ColorValue
    };
    Q_ENUM(Role)

    QString population;
    int     averageAge;
    bool    selected    { false };

    bool operator!=( const ModelItem& other )
    {
        return other.population != this->population
            || other.averageAge != this->averageAge;
    }

};
Q_DECLARE_METATYPE( ModelItem )



//
// ModelList
//
class ModelList
        : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY( int size READ size NOTIFY sizeChanged )

public:

    explicit ModelList(QObject* parent = nullptr);

    int rowCount( const QModelIndex & = QModelIndex() ) const override;
    int columnCount( const QModelIndex & = QModelIndex() ) const override;

    QVariant data( const QModelIndex& index, int role ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const override;

    int size() const;
    const QList<ModelItem>& list() const;

    Q_INVOKABLE void removeAt( int index );
    Q_INVOKABLE void add( const QString& population, const int averageAge );
    Q_INVOKABLE void select( int index );

    QHash<int, QByteArray> roleNames() const override;

private:

    QList<ModelItem>        mList;
    QHash<int, QByteArray>  mRoleNames;

public slots:

    void add(const ModelItem& item);
    void reset();

signals:

    void sizeChanged();
};



//
// ModelResults
//
class ModelResults : public QObject
{
    Q_OBJECT

    Q_PROPERTY( ModelList* list READ list CONSTANT )

public:

    explicit ModelResults( QObject *parent = nullptr );

    ModelList* list() const;

    Q_INVOKABLE void reset();

private:

    ModelList* mList;

};

#endif
