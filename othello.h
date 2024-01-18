#ifndef OTHELLO_H
#define OTHELLO_H

#include <vector>

class Othello {
public:
    Othello();
    void printBoard() const;
    bool makeMove(int row, int col, char player);
    bool isGameOver() const;
    char getWinner() const;
    void GameStart();  // 新たに追加されたメソッド

private:
    static const int BOARD_SIZE = 8;
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void initializeBoard();
    bool isValidMove(int row, int col, char player) const;
    bool flipTiles(int row, int col, char player, int deltaRow, int deltaCol);
};

#endif
