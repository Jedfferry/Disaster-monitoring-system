import QtQuick 1.0

Rectangle {
    width: 200; height: 200

    Loader {
        id: loader
        focus: true
    }

    MouseArea {
        anchors.fill: parent
        onClicked: loader.source = "KeyReader.qml"
    }

    Keys.onPressed: {
        console.log("Captured:", event.text);
    }
}
