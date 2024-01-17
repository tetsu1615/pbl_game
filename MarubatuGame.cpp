#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "MarubatuGame.h"

using namespace std;

Marubatsu_Game::Marubatsu_Game() {
    init();
}

//マス目を空欄にする関数
void Marubatsu_Game::init() {
    srand(static_cast<unsigned int>(time(NULL)));

    for (int x = 0; x < NUM; x++) {
        for (int y = 0; y < NUM; y++) {
            board[x][y] = ' ';
        }
    }

    // プレイヤーが先攻で始める
    turn = TURN_PLAYER;
}

//自分（プレイヤー）が打つ場所を決める関数
void Marubatsu_Game::decidePlayerPosition() {
    string x_s, y_s;
    cout << "どこに印を記入しますか？" << endl;
    //xの入力
    while (not(x_s == "0" || x_s == "1" || x_s == "2")) {
        cout << "0,1,2のいずれかを入力してください" << endl;
        cout << "xの入力(0 から " << NUM - 1 << "): ";
        cin >> x_s;
        cout << endl;
    }

    //yの入力
    while (not(y_s == "0" || y_s == "1" || y_s == "2")) {
        cout << "0,1,2のいずれかを入力してください" << endl;
        cout << "yの入力(0 から " << NUM - 1 << "): ";
        cin >> y_s;
        cout << endl;
    }
    int x_p, y_p;
    x_p = stoi(x_s);
    y_p = stoi(y_s);
    writeMark(x_p, y_p);
}

//相手（コンピュータ）の打つ場所を決める関数
void Marubatsu_Game::decideComPosition() {
    while (true) {
        int x_c, y_c;
        x_c = rand() % NUM;
        y_c = rand() % NUM;
        if ((isMarkable(x_c, y_c))) {
            writeMark(x_c, y_c);
            break;
        }
    }
}

//マス目に印があるかをチェックする関数
bool Marubatsu_Game::isMarkable(int x, int y) {
    if (board[x][y] != ' ') {
        //プレイヤーのターンのみ表示
        if (turn == TURN_PLAYER) {
            cout << "そのマスはすでに埋まっています..." << endl;
        }
        return false;
    }

    return true;
}

//打つ場所を決める関数
void Marubatsu_Game::decidePosition() {
    while (true) {
        if (turn == TURN_PLAYER) {
            decidePlayerPosition();
        }
        else {
            decideComPosition();
        }

        //埋まっているマス目のカウント
        count += count + 1;

        printBoard();

        if (judgeResult() != RESULT_NONE) {
            break;
        }

        if (judgeFull()) {
            cout << "引き分けです" << endl;
            break;
        }

        turn = nextTurn();
    }
}

//印をつける関数
void Marubatsu_Game::writeMark(int x, int y) {
    if (isMarkable(x, y)) {
        if (turn == TURN_PLAYER) {
            board[x][y] = 'o';
        }
        else {
            board[x][y] = 'x';
        }
    }
}

//マス目（ボードを）出力する関数
void Marubatsu_Game::printBoard() {
    cout << " ";
    for (int x = 0; x < NUM; x++) {
        cout << " " << x;
    }
    cout << endl;

    for (int y = 0; y < NUM; y++) {
        cout << y;
        for (int x = 0; x < NUM; x++) {
            cout << "|" << board[x][y];
        }
        cout << "|" << endl;
    }
    cout << endl;
}

//ボードが埋まっているか確認する関数
bool Marubatsu_Game::judgeFull() {
    for (int x = 0; x < NUM; x++) {
        for (int y = 0; y < NUM; y++) {
            if (board[x][y] == ' ') {
                return false;
            }
        }
    }
    return true;
}

//結果を判定する関数
Marubatsu_Game::RESULT Marubatsu_Game::judgeResult() {
    int count;
    char mark;

    // 記入された印を取得
    if (turn == TURN_PLAYER) {
        mark = 'o';
    }
    else {
        mark = 'x';
    }

    for (int y = 0; y < NUM; y++) {
        // 記入された印が横方向に３つ並んでいるかを確認
        count = 0;
        for (int x = 0; x < NUM; x++) {
            if (board[x][y] == mark) {
                count++;
            }
        }
        if (count == TARGET) {
            return turn == TURN_PLAYER ? RESULT_WIN : RESULT_LOSE;
        }
    }

    for (int x = 0; x < NUM; x++) {
        // 記入された印が縦方向に３つ並んでいるかを確認
        count = 0;
        for (int y = 0; y < NUM; y++) {
            if (board[x][y] == mark) {
                count++;
            }
        }
        if (count == TARGET) {
            return turn == TURN_PLAYER ? RESULT_WIN : RESULT_LOSE;
        }
    }

    // 記入された印が右下方向に３つ並んでいるかを確認
    count = 0;
    for (int k = 0; k < NUM; k++) {
        if (board[k][k] == mark) {
            count++;
        }
    }
    if (count == TARGET) {
        return turn == TURN_PLAYER ? RESULT_WIN : RESULT_LOSE;
    }

    // 記入された印が左下方向に３つ並んでいるかを確認
    count = 0;
    for (int k = 0; k < NUM; k++) {
        if (board[NUM - 1 - k][k] == mark) {
            count++;
        }
    }
    if (count == TARGET) {
        return turn == TURN_PLAYER ? RESULT_WIN : RESULT_LOSE;
    }

    // まだ勝敗が決定していない
    return RESULT_NONE;
}

//ターンを切り替える関数
Marubatsu_Game::TURN Marubatsu_Game::nextTurn() {
    return (turn == TURN_PLAYER) ? TURN_COM : TURN_PLAYER;
}

//結果を表示する関数
void Marubatsu_Game::printResult(RESULT result) {
    if (result == RESULT_WIN) {
        cout << "あなたの勝ちです!!!" << endl;
    }
    else if (result == RESULT_LOSE) {
        cout << "あなたの負けです!!!" << endl;
    }
    else if (result == RESULT_DRAW) {
        cout << "引き分けです" << endl;
    }
}

//実行する関数
void Marubatsu_Game::runGame() {
    int x = 0, y = 0;
    RESULT result = RESULT_NONE;
    TURN turn = TURN_PLAYER;
    while(result == RESULT_NONE) {
        // 1. ○×を記入する位置を決める
        decidePosition();

        // 2. ○×を記入する
        writeMark(x, y);

        // 3. 3x3のマスを表示する
        printBoard();

        // 4. 勝負の結果を判断する
        result = judgeResult();

        // 5. ターンを進める
        turn = nextTurn();

        // 6. 勝負の結果が決まっていない場合は1. に戻る
        if (result == RESULT_WIN || result == RESULT_LOSE) {
            break;
        }
    }

    cout << "--------------------------" << endl;
    // 7. 勝負の結果を表示する
    printResult(result);
}
