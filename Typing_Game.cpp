#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
#include"Typing_Game.h"

// �^�C�s���O�Q�[���̃N���X
// �R���X�g���N�^
Typing_Game::Typing_Game() {
// �P�ꃊ�X�g�̏�����
    words = { "programming", "computer", "keyboard", "language", "coding", "algorithm" };

// ����������̏�����
    srand(static_cast<unsigned>(time(nullptr)));
    }

    // �Q�[���̎��s���\�b�h
void Typing_Game::runGame() {
    cout << "�^�C�s���O�Q�[�����J�n���܂��I" << endl;
    cout << "�Q�[�����I������ꍇ�� Ctrl+C �������Ă��������B" << endl;

    while (true) {
        // �����_���ȒP����擾
        string targetWord = getRandomWord();

        // �v���C���[�ɒP���\��
        cout << "�^�C�v: " << targetWord << endl;

        // �v���C���[�̓��͂��󂯎��
        string Input;
        cout << "���͂��Ă�������: ";
        cin >> Input;

        // ���͂�������������
        if (Input == targetWord) {

            cout << "�����I" << endl;
        }
        else {

            cout << "�s�����B�Q�[���I�[�o�[�I" << endl;
            break;
        }
    }
}


string Typing_Game::getRandomWord() {

    int index = rand() % words.size();
    return words[index];
}