#ifndef _INCLUDE_TYPINGGAME_H_
#define _INCLUDE_TYPINGGAME_H_

#include <iostream>
#include <vector>
using namespace std;

class TypingGame {
public:
    //�R���X�g���N�^
    TypingGame();
    //�Q�[���̎��s
    void runGame();

private:
    //�^�C�v���邨��̑I��
    string getRandomWord() const;
    //����̃��X�g
    vector<string> words;
};

#endif