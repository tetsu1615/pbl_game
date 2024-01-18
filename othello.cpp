#include "othello.h"
#include <iostream>
using namespace std;

Othello::Othello() {
    initializeBoard();
    currentPlayer = 'X'; // 開始プレイヤー
}

void Othello::initializeBoard() {
    board.resize(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));

    // オセロボードの初期設定
    board[3][3] = board[4][4] = 'O'; // 白
    board[3][4] = board[4][3] = 'X'; // 黒
}

void Othello::printBoard() const {
    // ボードの列番号を表示
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i + 1 << ' ';
    }
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        // 行番号を表示
        cout << i + 1 << ' ';

        for (int j = 0; j < BOARD_SIZE; ++j) {
            // プレイヤータイルを "*"/"O" に変更
            if (board[i][j] == 'X') {
                cout << '*';
            }
            else if (board[i][j] == 'O') {
                cout << 'O';
            }
            else {
                cout << ' ';
            }
            cout << ' ';
        }
        cout << endl;
    }
}

bool Othello::isValidMove(int row, int col, char player) const {
    // セルが空であるか確認
    if (board[row][col] != ' ') {
        return false;
    }

    // 少なくとも1つの隣接する相手のタイルがあるか確認
    for (int deltaRow = -1; deltaRow <= 1; ++deltaRow) {
        for (int deltaCol = -1; deltaCol <= 1; ++deltaCol) {
            if (deltaRow == 0 && deltaCol == 0) {
                continue; // 現在のセルをスキップ
            }
            int r = row + deltaRow;
            int c = col + deltaCol;
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == (player == 'X' ? 'O' : 'X')) {
                // 隣接する相手のタイルが見つかった
                // タイルをひっくり返せる相手のタイルがあるか確認
                while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == (player == 'X' ? 'O' : 'X')) {
                    r += deltaRow;
                    c += deltaCol;
                }
                if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Othello::flipTiles(int row, int col, char player, int deltaRow, int deltaCol) {
    int r = row + deltaRow;
    int c = col + deltaCol;
    bool flipped = false;
    vector<pair<int, int>> tilesToFlip;  // ひっくり返す対象のタイルを記録

    while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == (player == 'X' ? 'O' : 'X')) {
        tilesToFlip.push_back({ r, c });
        r += deltaRow;
        c += deltaCol;
    }

    if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player) {
        // ライン上のタイルをひっくり返す
        for (const auto& tile : tilesToFlip) {
            board[tile.first][tile.second] = player;
            flipped = true;
        }
    }

    return flipped;
}

bool Othello::makeMove(int row, int col, char player) {
    if (!isValidMove(row, col, player)) {
        return false;
    }

    // プレイヤーのタイルをボードに配置
    board[row][col] = player;

    // すべての可能な方向で相手のタイルをひっくり返す
    for (int deltaRow = -1; deltaRow <= 1; ++deltaRow) {
        for (int deltaCol = -1; deltaCol <= 1; ++deltaCol) {
            if (deltaRow == 0 && deltaCol == 0) {
                continue;
            }
            flipTiles(row, col, player, deltaRow, deltaCol);
        }
    }

    // 次のプレイヤーに切り替える
    currentPlayer = (player == 'X' ? 'O' : 'X');

    return true;
}

bool Othello::isGameOver() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                // 空のセルがある場合、ゲームは終了していない
                return false;
            }
        }
    }

    return true;
}

char Othello::getWinner() const {
    int countX = 0, countO = 0;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 'X') {
                countX++;
            }
            else if (board[i][j] == 'O') {
                countO++;
            }
        }
    }

    if (countX > countO) {
        return 'X';
    }
    else if (countO > countX) {
        return 'O';
    }
    else {
        return 'T'; // 引き分け
    }
}

void Othello::GameStart() {
    cout << "オセロゲームを開始します！" << endl;
    cout << "ゲームを終了する場合は Ctrl+C を押してください。" << endl;
    while (!isGameOver()) {
        // 現在のボードの状態を表示
        printBoard();

        // 現在のプレイヤーの手を取得
        int row, col;
        cout << "プレイヤー" << (currentPlayer == 'X' ? "*（黒）" : "O（白）") << "の番です。行と列を入力してください (例: 1 2): ";
        cin >> row >> col;

        // 手を実行
        if (makeMove(row - 1, col - 1, currentPlayer)) {
            cout << "有効な置き方です。進行します。" << endl;
        }
        else {
            cout << "無効な置き方です。もう一度試してください。" << endl;
        }
    }

    // 最終的なボードの状態と勝者を表示
    printBoard();
    char winner = getWinner();
    if (winner == 'T') {
        cout << "引き分けです！" << endl;
    }
    else {
        cout << "プレイヤー" << (winner == 'X' ? "*（黒）" : "O（白）") << "が勝ちました！" << endl;
    }
}
