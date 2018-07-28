import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import Echo.Echo 0.1

ApplicationWindow {
    title: "echo"
    visible: true
    width: 800
    height: 600

    Echo {
        id: core
    }

    GridLayout {
        id: grid
        columns: 3
        x: 5
        y: 5

        Text {
            color: "white"
            font.pointSize: 18
            text: "new instrument symbol"
        }

        TextField {
            id: symbolInput
            font.pointSize: 18
        }

        Button {
            text: "send"
            onClicked: {
                core.addInstrument(symbolInput.text)
            }
        }

        Text {
            color: "white"
            font.pointSize: 18
            text: "last instrument symbol"
        }

        Text {
            color: "white"
            font.pointSize: 18
            text: core.lastInstrumentSymbol
        }
    }
}
