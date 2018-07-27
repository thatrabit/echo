import QtQuick 2.11
import QtQuick.Controls 2.4
import Echo.Echo 0.1

ApplicationWindow {
    title: "echo"
    visible: true

    Echo {
        id: core
    }
}
