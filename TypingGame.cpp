#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "TypingGame.h"
using namespace std;

TypingGame::TypingGame() {
        // 単語リストの初期化
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

        // 乱数生成器の初期化
        srand(static_cast<unsigned>(time(nullptr)));
    }

void TypingGame::runGame() {
        cout << "タイピングゲームを開始します！" << endl;
        cout << "制限時間は1分間です" << endl;
        cout << "※途中でゲームを終了する場合は Ctrl+C を押してください。" << endl;

        //開始時刻
        auto startTime = chrono::high_resolution_clock::now();
        //終了時刻
        auto endTime = startTime + chrono::minutes(1);
        //残り時間
        auto remainingTime = chrono::duration_cast<chrono::seconds>(endTime - chrono::high_resolution_clock::now());

        //カウントの初期化
        int correctCount = 0;
        int mistakeCount = 0;

        //制限時間内の場合
        while (chrono::high_resolution_clock::now() < endTime) {
            //残り時間の更新
            remainingTime = chrono::duration_cast<chrono::seconds>(endTime - chrono::high_resolution_clock::now());
            cout << "\n残り時間: " << remainingTime.count() << "秒" << endl;

            //タイプするお題の表示
            string targetWord = getRandomWord();
            cout << "タイプ: " << targetWord << endl;

            //入力
            string userInput;
            cout << "入力してください: ";
            cin >> userInput;

            //正解の場合
            if (userInput == targetWord) {
                cout << "正解！" << endl;
                correctCount++;
            }
            //不正解の場合
            else {
                cout << "不正解。" << endl;
                mistakeCount++;
            }
        }
        //結果発表
        cout << "\nゲーム終了！" << endl;
        cout << "正答数: " << correctCount << endl;
        cout << "ミス数: " << mistakeCount << endl;
    }

//単語の選択
string TypingGame::getRandomWord() const {
        int index = rand() % words.size();
        return words[index];
    }