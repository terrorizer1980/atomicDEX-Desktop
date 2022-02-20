//! Qt Imports.
import QtQuick 2.15

//! Project Imports
import App 1.0
import "../Constants"

Text
{
    property string text_value
    property bool   enabled: true
    property bool   privacy: false
    property bool   monospace: false

    Behavior on color
    {
        ColorAnimation
        {
            duration: Style.animationDuration
        }
    }

    font: monospace ? DexTypo.monoSmall : DexTypo.body2

    color: enabled || monospace ? DexTheme.foregroundColor : DexTheme.textDisabledColor

    text: privacy && General.privacy_mode ? General.privacy_text : text_value
    wrapMode: Text.WordWrap

    onLinkActivated: Qt.openUrlExternally(link)
    linkColor: color
}
