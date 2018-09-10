#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::endl;

class CheckKing{
    private:
        static unsigned const int krows = 8;
        static unsigned const int kcols = 8;
        char board[krows][kcols];
        int gameNum = 0;

    public:
        //what is the file name?
        bool getBoard();
        bool checkBoard(char king);
        bool allDots();
        bool leftRight(char direction, int i, int j);
        bool upDown(char direction, int i, int j);
        bool upLR(char direction, int i, int j);
        bool downLR(char direction, int i, int j);
        bool knight(int i, int j);
        bool isPiece(char king, char piece, int i, int j);
        bool pawnCheck(bool isWhite, int i, int j);
};