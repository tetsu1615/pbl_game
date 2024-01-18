#include <iostream>
#include <string>
using namespace std;
#include "Typing_Game.h"
#include "othello.h"
#include "MarubatuGame.h"

int main(void) {
	cout << "1. タイピングゲーム" << endl;
	cout << "2. てつのゲーム" << endl;
	cout << "3. 〇×ゲーム" << endl << endl;
	cout << "プレイするゲーム番号 >> ";
	string GameNumber;
	cin >> GameNumber;
	cout << endl;

	while (not(GameNumber == "1" || GameNumber == "2" || GameNumber == "3")) {
		cout << "1, 2, 3のいずれかを入力してください" << endl;
		cout << "プレイするゲーム番号 >> ";
		cin >> GameNumber;
		cout << endl;
	}

	Typing_Game game1;
	Othello game2;
	Marubatsu_Game game3;

	switch (stoi(GameNumber))
	{
	case(1):
		game1.runGame();
	case(2):
		game2.GameStart();
	case(3):
		game3.runGame();
	default:
		break;
	}
	
	return 0;
}
