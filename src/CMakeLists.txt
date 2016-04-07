set(chessboard_SRCS
    chessboard.cpp
    Board.cpp)

add_executable(chessboard
    ${chessboard_SRCS}
    ../assets/chessboard.qrc)

qt5_use_modules(chessboard
    Quick)
