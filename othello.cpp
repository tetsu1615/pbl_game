#include "othello.h"
#include <iostream>
using namespace std;

Othello::Othello() {
    initializeBoard();
    currentPlayer = 'X'; // �J�n�v���C���[
}

void Othello::initializeBoard() {
    board.resize(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));

    // �I�Z���{�[�h�̏����ݒ�
    board[3][3] = board[4][4] = 'O'; // ��
    board[3][4] = board[4][3] = 'X'; // ��
}

void Othello::printBoard() const {
    // �{�[�h�̗�ԍ���\��
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i + 1 << ' ';
    }
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        // �s�ԍ���\��
        cout << i + 1 << ' ';

        for (int j = 0; j < BOARD_SIZE; ++j) {
            // �v���C���[�^�C���� "*"/"O" �ɕύX
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
    // �Z������ł��邩�m�F
    if (board[row][col] != ' ') {
        return false;
    }

    // ���Ȃ��Ƃ�1�̗אڂ��鑊��̃^�C�������邩�m�F
    for (int deltaRow = -1; deltaRow <= 1; ++deltaRow) {
        for (int deltaCol = -1; deltaCol <= 1; ++deltaCol) {
            if (deltaRow == 0 && deltaCol == 0) {
                continue; // ���݂̃Z�����X�L�b�v
            }
            int r = row + deltaRow;
            int c = col + deltaCol;
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == (player == 'X' ? 'O' : 'X')) {
                // �אڂ��鑊��̃^�C������������
                // �^�C�����Ђ�����Ԃ��鑊��̃^�C�������邩�m�F
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
    vector<pair<int, int>> tilesToFlip;  // �Ђ�����Ԃ��Ώۂ̃^�C�����L�^

    while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == (player == 'X' ? 'O' : 'X')) {
        tilesToFlip.push_back({ r, c });
        r += deltaRow;
        c += deltaCol;
    }

    if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player) {
        // ���C����̃^�C�����Ђ�����Ԃ�
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

    // �v���C���[�̃^�C�����{�[�h�ɔz�u
    board[row][col] = player;

    // ���ׂẲ\�ȕ����ő���̃^�C�����Ђ�����Ԃ�
    for (int deltaRow = -1; deltaRow <= 1; ++deltaRow) {
        for (int deltaCol = -1; deltaCol <= 1; ++deltaCol) {
            if (deltaRow == 0 && deltaCol == 0) {
                continue;
            }
            flipTiles(row, col, player, deltaRow, deltaCol);
        }
    }

    // ���̃v���C���[�ɐ؂�ւ���
    currentPlayer = (player == 'X' ? 'O' : 'X');

    return true;
}

bool Othello::isGameOver() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                // ��̃Z��������ꍇ�A�Q�[���͏I�����Ă��Ȃ�
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
        return 'T'; // ��������
    }
}

void Othello::GameStart() {
    cout << "�I�Z���Q�[�����J�n���܂��I" << endl;
    cout << "�Q�[�����I������ꍇ�� Ctrl+C �������Ă��������B" << endl;
    while (!isGameOver()) {
        // ���݂̃{�[�h�̏�Ԃ�\��
        printBoard();

        // ���݂̃v���C���[�̎���擾
        int row, col;
        cout << "�v���C���[" << (currentPlayer == 'X' ? "*�i���j" : "O�i���j") << "�̔Ԃł��B�s�Ɨ����͂��Ă������� (��: 1 2): ";
        cin >> row >> col;

        // ������s
        if (makeMove(row - 1, col - 1, currentPlayer)) {
            cout << "�L���Ȓu�����ł��B�i�s���܂��B" << endl;
        }
        else {
            cout << "�����Ȓu�����ł��B������x�����Ă��������B" << endl;
        }
    }

    // �ŏI�I�ȃ{�[�h�̏�ԂƏ��҂�\��
    printBoard();
    char winner = getWinner();
    if (winner == 'T') {
        cout << "���������ł��I" << endl;
    }
    else {
        cout << "�v���C���[" << (winner == 'X' ? "*�i���j" : "O�i���j") << "�������܂����I" << endl;
    }
}
