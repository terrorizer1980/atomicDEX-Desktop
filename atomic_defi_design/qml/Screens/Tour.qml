//! Qt Imports
import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0
import Qt.labs.settings 1.0
import QtQml 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Universal 2.12

import Qaterial 1.0 as Qaterial

// Project Imports
import "../Components"
import "../Constants"


Qaterial.Dialog {


    id: setting_modal
    width: 850
    height: 650
    anchors.centerIn: parent
    dim: true
    modal: true
    title: "Tour"
    header: Item{}
    Overlay.modal: Item {
        Rectangle {
            anchors.fill: parent
            color: theme.surfaceColor
            opacity: .7
        }
    }
    background: FloatingBackground {
        color: theme.dexBoxBackgroundColor
        radius: 3
    }
    padding: 0
    topPadding: 0
    bottomPadding: 0
    Item {
        width: parent.width
        height: 60
        Qaterial.AppBarButton {
            anchors.right: parent.right
            anchors.rightMargin: 10
            foregroundColor: theme.foregroundColor
            icon.source: Qaterial.Icons.close
            anchors.verticalCenter: parent.verticalCenter
            onClicked: setting_modal.close()
        }
        Row {
            anchors.verticalCenter: parent.verticalCenter
            leftPadding: 20
            DexLabel {
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Tour of App")
                font: theme.textType.head6
            }
        }

        Qaterial.DebugRectangle {
            anchors.fill: parent
            visible: false
        }
    }
    Item {
        width: parent.width
        height: parent.height-110
        y:60
        SwipeView {
            id: swipeTour
            anchors.fill: parent
            clip: true
            Repeater {
                model: ListModel {
                    ListElement {
                        name: "Welcome to AtomicDex"
                        description: "kdnskqsdfdhdfj fkqdlf"
                        image: "https://komodoplatform.com/en/blog/content/images/size/w2000/2021/03/default_komodo_960x480-47.jpg"
                        reverse: false
                    }
                    ListElement {
                        name: "Lets Make a tour"
                        description: "kdnskqsdfdhdfj fkqdlf"
                        image: "https://coin-ratgeber.de/wp-content/uploads/2021/02/Screenshot-2021-02-28-at-23.22.49.png"
                        reverse: true
                    }
                    ListElement {
                        name: "Welcome to AtomicDex"
                        description: "kdnskqsdfdhdfj fkqdlf"
                        image: "https://komodoplatform.com/assets/img/illustration/komodo-official-wallet-AtomicDEX.png"
                        reverse: false
                    }
                }
                delegate: Item {
                    Image {
                        width: parent.width-50
                        height: parent.height-50
                        anchors.centerIn: parent
                        source: image
                        opacity: .5

                    }
                    Column {
                        anchors.fill: parent
                        padding: 20
                        DexLabel {
                            horizontalAlignment: reverse? Text.AlignRight : Text.AlignLeft 
                            width: parent.width-20
                            leftPadding: 20
                            rightPadding: 20
                            wrapMode: Label.Wrap
                            font: _font.head4
                            text: name
                        }
                        DexLabel {
                            horizontalAlignment: reverse?  Text.AlignRight : Text.AlignLeft 
                            width: parent.width-20
                            leftPadding: 20
                            rightPadding: 20
                            wrapMode: Label.Wrap
                            text: description
                        }
                    }
                    
                }
            }
        }
        PageIndicator {
            currentIndex: swipeTour.currentIndex
            count: swipeTour.count
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
        
    }
    Item {
        width: parent.width-15
        height: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        Row {
            anchors.right: parent.right 
            height: parent.height
            spacing: 15
            
            DexSelectableButton {
                id: backbutton
                selected: true
                visible:  swipeTour.currentIndex>0
                anchors.horizontalCenter: undefined
                anchors.verticalCenter: parent.verticalCenter
                text: ""
                height: 40
                width: backRow.width+30
                Row {
                    id: backRow
                    anchors.centerIn: parent
                    Qaterial.ColorIcon {
                        anchors.verticalCenter: parent.verticalCenter
                        source: Qaterial.Icons.chevronLeft
                    }
                    spacing: 10
                    DexLabel {
                        text: qsTr("Back")
                        color: theme.buttonColorTextEnabled
                        anchors.verticalCenter: parent.verticalCenter
                        font: theme.textType.button
                    }
                    opacity: .6
                }
                onClicked: {
                    swipeTour.currentIndex = swipeTour.currentIndex-1 
                }
            }
            DexSelectableButton {
                id: nextbutton
                visible: swipeTour.count>0 && swipeTour.currentIndex!=swipeTour.count-1
                selected: true
                anchors.horizontalCenter: undefined
                anchors.verticalCenter: parent.verticalCenter
                text: ""
                height: 40
                width: nextRow.width+30
                Row {
                    id: nextRow
                    layoutDirection: Qt.RightToLeft 
                    anchors.centerIn: parent
                    Qaterial.ColorIcon {
                        anchors.verticalCenter: parent.verticalCenter
                        source: Qaterial.Icons.chevronRight
                    }
                    spacing: 10
                    DexLabel {
                        text: qsTr("Next")
                        color: theme.buttonColorTextEnabled
                        anchors.verticalCenter: parent.verticalCenter
                        font: theme.textType.button
                    }
                    opacity: .6
                }
                onClicked: {
                    swipeTour.currentIndex = swipeTour.currentIndex+1
                }
            }
        }
    }
}
