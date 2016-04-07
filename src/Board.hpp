#ifndef CHESSBOARD_BOARD_HPP
#define CHESSBOARD_BOARD_HPP

#include <QObject>

#include <array>

namespace chessboard {

typedef signed char Figure;

enum Colors {
    kBlack = -1,
    kWhite =  1
};

enum Figures {
    kPawn = 1,
    kRook,
    kKnight,
    kBishop,
    kQueen,
    kKing,
    kInvalid,
};

constexpr int kNumberOfFields = 64;

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent=nullptr);

    Q_INVOKABLE QString getFigure(int index) const;

private:
    std::array<Figure, kNumberOfFields> m_fields;
};

}  // namespace chessboard

#endif  // CHESSBOARD_BOARD_HPP
