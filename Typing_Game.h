#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// タイピングゲームのクラス
class Typing_Game {
public:
    // コンストラクタ
    Typing_Game();

    // ゲームの実行メソッド
    void runGame();

    // 単語リストからランダムな単語を取得するメソッド
    string getRandomWord();

    // 単語リスト
    vector<string> words;
};