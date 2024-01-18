#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "TypingGame.h"
using namespace std;

TypingGame::TypingGame() {
        // �P�ꃊ�X�g�̏�����
    words = { "age", "airplane", "are", "artist", "animal", "away", "after", "among", "also", "arm", "bike", "bad",
 "building", "blow", "be", "bedroom", "brother", "boat", "ball", "boy", "cheap", "cat", "cow",
"coat", "company", "count", "clever", "call", "catch", "cold", "doctor", "dream", "during",
"different", "dangerous", "difficult", "draw", "daughter", "discover", "dirty", "easy", "eleven",
"eighteen", "east", "ever", "ear", "everywhere", "everybody", "every", "either", "finish",
"friendly", "father", "future", "farm", "forest", "fast", "factory", "fight", "forty", "gone", "grow",
"grandmother", "grass", "gray", "gentleman", "gas", "guitar", "get", "good", "husband", "he",
"history", "heart", "hour", "hello", "half", "happy", "happiness", "honey", "its", "ill", "interest",
"inside", "important", "is", "I", "it", "if", "in", "joy", "July", "just", "job", "juice", "join", "June",
"joke", "jump", "junior", "kid", "know", "kill", "keep", "knife", "king", "knee", "kind", "kick",
"kitchen", "late", "land", "life", "long", "leg", "library", "lose", "lip", "lion", "lunch", "many",
"master", "musician", "may", "music", "moon", "me", "man", "mountain", "Mr.", "nail",
"notebook", "nothing", "number", "next", "never", "nose", "north", "natural", "November",
"order", "outside", "once", "ours", "oh", "oil", "office", "other", "OK", "only", "pick", "past",
"parent", "plane", "photograph", "practice", "play", "post", "page", "picture", "queen",
"question", "quarter", "quiet", "quick", "quickly", "red", "river", "ready", "round", "rocket",
"rainy", "rain", "rice", "roof", "rule", "spoon", "someone", "station", "star", "shake", "scene",
"sleepy", "strange", "soft", "shop", "thick", "tomato", "tooth", "turn", "though", "tennis",
"through", "three", "take", "the", "use", "upon", "until", "usual", "up", "usually", "understand",
"under", "umbrella", "useful", "voice", "video-tape", "visit", "visitor", "very", "violin", "video",
"vegetable", "vacation", "village", "wake", "way", "wise", "whose", "wet", "while", "week",
"welcome", "wine", "well", "young", "year", "yes", "yesterday", "yellow", "you", "your", "yours",
"yard", "zoo"
    };

        // ����������̏�����
        srand(static_cast<unsigned>(time(nullptr)));
    }

void TypingGame::runGame() {
        cout << "�^�C�s���O�Q�[�����J�n���܂��I" << endl;
        cout << "�������Ԃ�1���Ԃł�" << endl;
        cout << "���r���ŃQ�[�����I������ꍇ�� Ctrl+C �������Ă��������B" << endl;

        //�J�n����
        auto startTime = chrono::high_resolution_clock::now();
        //�I������
        auto endTime = startTime + chrono::minutes(1);
        //�c�莞��
        auto remainingTime = chrono::duration_cast<chrono::seconds>(endTime - chrono::high_resolution_clock::now());

        //�J�E���g�̏�����
        int correctCount = 0;
        int mistakeCount = 0;

        //�������ԓ��̏ꍇ
        while (chrono::high_resolution_clock::now() < endTime) {
            //�c�莞�Ԃ̍X�V
            remainingTime = chrono::duration_cast<chrono::seconds>(endTime - chrono::high_resolution_clock::now());
            cout << "\n�c�莞��: " << remainingTime.count() << "�b" << endl;

            //�^�C�v���邨��̕\��
            string targetWord = getRandomWord();
            cout << "�^�C�v: " << targetWord << endl;

            //����
            string userInput;
            cout << "���͂��Ă�������: ";
            cin >> userInput;

            //�����̏ꍇ
            if (userInput == targetWord) {
                cout << "�����I" << endl;
                correctCount++;
            }
            //�s�����̏ꍇ
            else {
                cout << "�s�����B" << endl;
                mistakeCount++;
            }
        }
        //���ʔ��\
        cout << "\n�Q�[���I���I" << endl;
        cout << "������: " << correctCount << endl;
        cout << "�~�X��: " << mistakeCount << endl;
    }

//�P��̑I��
string TypingGame::getRandomWord() const {
        int index = rand() % words.size();
        return words[index];
    }