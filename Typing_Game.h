#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// �^�C�s���O�Q�[���̃N���X
class Typing_Game {
public:
    // �R���X�g���N�^
    Typing_Game();

    // �Q�[���̎��s���\�b�h
    void runGame();

    // �P�ꃊ�X�g���烉���_���ȒP����擾���郁�\�b�h
    string getRandomWord();

    // �P�ꃊ�X�g
    vector<string> words;
};