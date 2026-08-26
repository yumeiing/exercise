import QtQuick

Rectangle {
    id: root
    width: 220; height: 260
    color: "#a1a1a1"

    Image {
        width: parent.width; height: parent.width

        id: car
        source: "./images/gunge.png"
        x: 0; y: parent.height-parent.width
    }

    Text {
        //un-name

        color: "white"
        text: qsTr("gunmu...")
    }
}
