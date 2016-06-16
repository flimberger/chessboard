#include "Board.hpp"

#include <cstdlib>
#include <sstream>

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

constexpr int kVerticalMoveFactor = 8;
constexpr int kDiagonalLeftMoveFactor = 7;
constexpr int kDiagonalRightMoveFactor = 9;

// Moves of Knight
#if 0
constexpr int kKnightMoves[] = {
    6, 10, 15, 17
};
#endif

static Colors getColor(Figure figure)
{
    if (figure < 0)
	return kBlack;
    else
	return kWhite;
}

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

int Board::getFigure(int index) const
{
	if (index < 0 || index > (kNumberOfFields - 1))
		return 0;

	return m_fields[index];
}

QString Board::getFigureAssetUrl(int figure) const
{
    auto url = std::stringstream();

    if (figure != 0) {
        url << "qrc:/figurines/";
        if (figure < 0)
            url << "black";
        else
            url << "white";
        url << "_";
        switch (std::abs(figure)) {
        case kPawn:
            url << "pawn";
            break;
        case kRook:
            url << "rook";
            break;
        case kKnight:
            url << "knight";
            break;
        case kBishop:
            url << "bishop";
            break;
        case kQueen:
            url << "queen";
            break;
        case kKing:
            url << "king";
            break;
        }
        url << ".svg";
    }

    return QString::fromUtf8(url.str().c_str());
}

std::vector<int> Board::getPossibleTargets(int figure, int position)
{
	auto possibleTargets = std::vector<int>();

	switch (std::abs(figure)) {
		case kPawn:
			possibleTargets = getPawnTargets(position, getColor(figure));
			break;
		case kRook:
			break;
		case kKnight:
			break;
		case kBishop:
			break;
		case kQueen:
			break;
		case kKing:
			break;
	}

	return possibleTargets;
}

std::vector<int> Board::getPawnTargets(int position, Colors color) const
{
    auto positions = std::vector<int>();

    if (color == kBlack) {
	for (int i = 0; i < 3; ++i) {
	    int nextPosition;
	    
	    // Hit if target diagonal right
	    nextPosition = position + kDiagonalRightMoveFactor * 1;
	    if (getFigure(nextPosition) != 0)
		positions.push_back(nextPosition);
	    // Hit if target diagonal left
	    nextPosition = position + kDiagonalLeftMoveFactor * 1;
	    if (getFigure(nextPosition) != 0)
		positions.push_back(nextPosition);
	    // Advance if next field is free
	    nextPosition = position + kVerticalMoveFactor * 1;
	    if (getFigure(nextPosition) == 0)
		positions.push_back(nextPosition);
	    // Special rule for the beginning
	    if ((position > 7) && (position < 16) && (getFigure(nextPosition) == 0) && (getFigure(nextPosition + kVerticalMoveFactor * 1) == 0))
		positions.push_back(nextPosition + kVerticalMoveFactor * 1);
	}
    } else {
    }

    return positions;
}

}  // namespace chessboard
