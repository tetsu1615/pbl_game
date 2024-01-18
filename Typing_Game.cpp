#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
#include"Typing_Game.h"

// タイピングゲームのクラス
// コンストラクタ
Typing_Game::Typing_Game() {
// 単語リストの初期化
    words = { "programming", "computer", "keyboard", "language", "coding", "algorithm" };

// 乱数生成器の初期化
    srand(static_cast<unsigned>(time(nullptr)));
    }

    // ゲームの実行メソッド
void Typing_Game::runGame() {
    cout << "タイピングゲームを開始します！" << endl;
    cout << "ゲームを終了する場合は Ctrl+C を押してください。" << endl;

    while (true) {
        // ランダムな単語を取得
        string targetWord = getRandomWord();

        // プレイヤーに単語を表示
        cout << "タイプ: " << targetWord << endl;

        // プレイヤーの入力を受け取る
        string Input;
        cout << "入力してください: ";
        cin >> Input;

        // 入力が正しいか判定
        if (Input == targetWord) {

            cout << "正解！" << endl;
        }
        else {

            cout << "不正解。ゲームオーバー！" << endl;
            break;
        }
    }
}


string Typing_Game::getRandomWord() {

    int index = rand() % words.size();
    return words[index];
}