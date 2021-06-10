import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Qt.labs.qmlmodels 1.0

import Backend 1.0

ApplicationWindow
{
  id:      root
  visible: true

  width:  768
  height: 450

  minimumWidth:  768
  minimumHeight: 450

  property string backendReference: Backend.objectName

  TableView
  {
    id: tableView

    columnWidthProvider: function( column )
    {
      return 100;
    }

    rowHeightProvider: function( column )
    {
      return 23;
    }

    anchors.fill: parent
    topMargin:    columnsHeader.implicitHeight

    model: Backend.modelResults.list

    ScrollBar.horizontal: ScrollBar {}
    ScrollBar.vertical:   ScrollBar {}

    clip: true

    delegate: DelegateChooser
    {
      DelegateChoice
      {
        delegate: Rectangle
        {
          color: selected

          Text
          {
            text: display
            anchors.fill: parent
            anchors.margins: 10
            color: 'black'
            font.pixelSize: 15
            verticalAlignment: Text.AlignVCenter
          }

          MouseArea
          {
            anchors.fill: parent

            onClicked:
            {
              var idx = Backend.modelResults.list.index( row, column )

              console.log( "Clicked cell: ", idx.row, " ", Backend.modelResults.list.data( idx ) )

              Backend.modelResults.list.select( idx.row );
            }
          }
        }
      }

      //      DelegateChoice {
      ////        roleValue: "display"

      //        Rectangle
      //        {
      //          Text
      //          {
      //            text: display
      //            anchors.fill: parent
      //            anchors.margins: 10
      //            color: 'black'
      //            font.pixelSize: 15
      //            verticalAlignment: Text.AlignVCenter
      //          }
      //        }
      //      }

    }

    //        Rectangle
    //    {
    //      Text
    //      {
    //        text: display
    //        anchors.fill: parent
    //        anchors.margins: 10
    //        color: 'black'
    //        font.pixelSize: 15
    //        verticalAlignment: Text.AlignVCenter
    //      }
    //    }

    Rectangle // mask the headers
    {
      z: 3

      color: "#222222"

      y: tableView.contentY
      x: tableView.contentX

      width:  tableView.leftMargin
      height: tableView.topMargin
    }

    Row
    {
      id: columnsHeader
      y:  tableView.contentY

      z: 2

      Repeater
      {
        model: tableView.columns > 0 ? tableView.columns : 1

        Label
        {
          width:  tableView.columnWidthProvider(modelData)
          height: 35

          text: Backend.modelResults.list.headerData( modelData, Qt.Horizontal )

          font.pixelSize:    15
          padding:           10
          verticalAlignment: Text.AlignVCenter

          background: Rectangle
          {
            color: "#eeeeee"
          }
        }
      }
    }

    ScrollIndicator.horizontal: ScrollIndicator { }
    ScrollIndicator.vertical: ScrollIndicator { }
  }
}
