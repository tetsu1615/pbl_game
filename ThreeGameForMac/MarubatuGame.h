class Marubatsu_Game {
public:
    Marubatsu_Game();
    void runGame();

private:
    //結果
    enum RESULT {
        RESULT_WIN,
        RESULT_LOSE,
        RESULT_DRAW,
        RESULT_NONE
    };

    //ターン
    enum TURN {
        TURN_PLAYER,
        TURN_COM
    };

    static const int NUM = 3; //縦、横それぞれの大きさ
    static const int TARGET = NUM;

    int count = 0; //ボードの埋まっているマス目のチェック
    char board[NUM][NUM];
    TURN turn;

    void init();
    void decidePlayerPosition();
    void decideComPosition();
    bool isMarkable(int x, int y);
    void decidePosition();
    void writeMark(int x, int y);
    void printBoard();
    bool judgeFull();
    RESULT judgeResult();
    TURN nextTurn();
    void printResult(RESULT result);
};