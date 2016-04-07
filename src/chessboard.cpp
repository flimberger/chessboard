#include <QtCore/QUrl>

#include <QtGui/QGuiApplication>

#include <QtQml/QQmlContext>

#include <QtQuick/QQuickView>

#include "Board.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    chessboard::Board board;

    view.rootContext()->setContextProperty("g_board", &board);
    view.setSource(QUrl("qrc:/qml/Board.qml"));
    view.show();

    return app.exec();
}
