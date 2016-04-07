import QtQuick 2.5

Item {
    property int fieldSize: 50

    id: board
    width: fieldSize * 8
    height: fieldSize * 8

    Grid {
        rows: 8
        columns: 8

        Repeater {
            model: parent.rows * parent.columns


            Rectangle {
                property int index: Positioner.index

                width: board.fieldSize
                height: board.fieldSize
                color: Math.floor(index / 8) % 2 == 0
                       ? (index % 2 == 0 ? "#ccc" : "#333")
                       : (index % 2 == 0 ? "#333" : "#ccc")

                Image {
                    source: { g_board.getFigure(index); }
                    anchors.centerIn: parent
                }
            }
        }
    }
}
