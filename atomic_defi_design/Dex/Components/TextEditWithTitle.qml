import QtQuick 2.15
import QtQuick.Layouts 1.15
import Qaterial 1.0 as Qaterial
import "../Constants" as Constants
import App 1.0

ComponentWithTitle
{
    id: control

    property alias text: text.text_value
    property alias value_color: text.color
    property alias privacy: text.privacy

    property bool   monospace: false
    property string linkURL: ""
    property string onCopyNotificationTitle: ""
    property string onCopyNotificationMsg: qsTr("copied to clipboard")

    RowLayout
    {
        Layout.fillWidth: true

        DexLabel
        {
            id: text
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredHeight: show_content ? contentHeight : 0

            clip: true
            opacity: show_content ? 1 : 0
            color: DexTheme.foregroundColor
            textFormat: TextEdit.AutoText
            monospace: control.monospace
            Behavior on Layout.preferredHeight { SmoothedAnimation { id: expand_animation; duration: Constants.Style.animationDuration * 2; velocity: -1 } }
            Behavior on opacity { SmoothedAnimation { duration: expand_animation.duration; velocity: -1 } }
        }

        DefaultCopyIcon
        {
            copyText: control.text
            notifyTitle: control.onCopyNotificationTitle
            notifyMsg: control.onCopyNotificationMsg
            xPos: text.implicitWidth + 10
            iconSize: 14
        }

        DefaultLinkIcon
        {
            linkURL: control.linkURL
            xPos: text.implicitWidth + 10
            iconSize: 14
        }

        Item { Layout.fillWidth: true }
    }
}
