#ifndef _INCLUDE_TYPINGGAME_H_
#define _INCLUDE_TYPINGGAME_H_

#include <iostream>
#include <vector>
using namespace std;

class TypingGame {
public:
    //コンストラクタ
    TypingGame();
    //ゲームの実行
    void runGame();

private:
    //タイプするお題の選択
    string getRandomWord() const;
    //お題のリスト
    vector<string> words;
};

#endif