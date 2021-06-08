import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

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

    ScrollView {
        id: scrollView

        clip: true

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.topMargin: 10
        anchors.bottomMargin: 10

        hoverEnabled: false

        TableView {
            id: modelResults

            model: Backend.modelResults.list

            delegate: Rectangle {
                implicitWidth: 100
                implicitHeight: 18

                Text {
                    text: display
                }
            }
        }
    }
}

