#include "Board.hpp"

#include <cstdlib>

namespace chessboard {

constexpr Figure kBP = kBlack * kPawn;
constexpr Figure kBR = kBlack * kRook;
constexpr Figure kBN = kBlack * kKnight;
constexpr Figure kBB = kBlack * kBishop;
constexpr Figure kBQ = kBlack * kQueen;
constexpr Figure kBK = kBlack * kKing;
constexpr Figure kWP = kWhite * kPawn;
constexpr Figure kWR = kWhite * kRook;
constexpr Figure kWN = kWhite * kKnight;
constexpr Figure kWB = kWhite * kBishop;
constexpr Figure kWQ = kWhite * kQueen;
constexpr Figure kWK = kWhite * kKing;

#define QCHESS_START_LAYOUT {{               \
    kBR, kBN, kBB, kBQ, kBK, kBB, kBN, kBR,  \
    kBP, kBP, kBP, kBP, kBP, kBP, kBP, kBP,  \
      0,   0,   0,   0,   0,   0,   0,   0,  \
      0,   0,   0,   0,   0,   0,   0,   0,  \
      0,   0,   0,   0,   0,   0,   0,   0,  \
      0,   0,   0,   0,   0,   0,   0,   0,  \
    kWP, kWP, kWP, kWP, kWP, kWP, kWP, kWP,  \
    kWR, kWN, kWB, kWQ, kWK, kWB, kWN, kWR   \
}}

Board::Board(QObject *parent)
  : QObject(parent),
    m_fields(QCHESS_START_LAYOUT)
{}

#undef QCHESS_START_LAYOUT

QString Board::getFigure(int index) const
{
    auto url = QString();

    if (index < 0 || index > (kNumberOfFields - 1))
        return url;

    int figure = m_fields[index];

    if (figure != 0) {
        url = "qrc:/figurines/";
        if (figure < 0)
            url += "black";
        else
            url += "white";
        url += "_";
        switch (std::abs(figure)) {
        case kPawn:
            url += "pawn";
            break;
        case kRook:
            url += "rook";
            break;
        case kKnight:
            url += "knight";
            break;
        case kBishop:
            url += "bishop";
            break;
        case kQueen:
            url += "queen";
            break;
        case kKing:
            url += "king";
            break;
        }
        url += ".svg";
    }

    return url;
}

}  // namespace chessboard
