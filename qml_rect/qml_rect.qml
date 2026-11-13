import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("window")

    property string textToShow: "hello"

    Row {
        anchors.centerIn: parent
        spacing: 20

        Rectangle {
            width: 100
            height: this.width
            color: "red"
            border.color: "black"
            border.width: 5
            radius: 15

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    textToShow = "red"
                }
            }
        }

        Rectangle {
            width: 100
            height: this.width
            color: "blue"
            border.color: "black"
            border.width: 5
            radius: 15

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    textToShow = "blue"
                }
            }
        }

        Rectangle {
            width: 100
            height: this.width
            color: "green"
            border.color: "black"
            border.width: 5
            radius: 15

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    textToShow = "green"
				}
			}
		}

        Rectangle {
            width: 100
            height: this.width
            color: "dodgerblue"
            border.color: "black"
            border.width: 5
            radius: 60

            Text {
                anchors.centerIn: parent
                text: textToShow
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("you clicked this rect")
                }
            }
        }
    }
}
