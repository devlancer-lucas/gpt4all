import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Basic
import Qt5Compat.GraphicalEffects

Button {
    id: myButton
    padding: 10
    property alias source: image.source
    contentItem: Text {
        text: myButton.text
        horizontalAlignment: Text.AlignHCenter
        color: myButton.enabled ? theme.textColor : theme.mutedTextColor
        Accessible.role: Accessible.Button
        Accessible.name: text
    }

    background: Item {
        anchors.fill: parent
        Rectangle {
            anchors.fill: parent
            color: "transparent"
            visible: myButton.checkable && myButton.checked
            border.color: theme.backgroundLightest
            border.width: 1
            radius: 10
        }
        Image {
            id: image
            anchors.centerIn: parent
            mipmap: true
            width: 30
            height: 30
        }
        ColorOverlay {
            anchors.fill: image
            source: image
            color: myButton.hovered ? theme.textColor : "transparent"
        }
    }
    Accessible.role: Accessible.Button
    Accessible.name: text
}