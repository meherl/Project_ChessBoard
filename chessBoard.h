#include "checkKing.cpp"

bool CheckKing::getBoard () {
    ifstream fin("board.txt");
    string line;

    for (int i = 0; getline(fin, line);) {
        if (line.size() == krows) {
            for (int j = 0; j < line.size(); j++) {
                board[i][j] = line[j];
            }
            i++;
        }
        if (i == kcols) {
            gameNum++;
            if (allDots()) {
                cout << "ALL DOTS" << endl;
                return false;
            }
            else if (checkBoard('k') == true) {
                cout << "Game #" << gameNum << ": white king is in check" << endl;
            }
            else if (checkBoard('K') == true) {
                cout << "Game #" << gameNum << ": black king is in check" << endl;
            }
            else {
                cout << "Game #" << gameNum << ": no king is in check" << endl;
            }
            i = 0;
        }
    }
}

bool CheckKing::checkBoard(char king) {
    for (int i = 0; i < kcols; i++) {
        for (int j = 0; j < krows; j++) {
            if (board[i][j] == king) {
                if (pawnCheck(islower(board[i][j]), i, j)) {
                    return true;
                }
                if (knight(i, j)) {
                    return true;
                }
                if (i == 0) {
                    if (upDown('d', i, j)) {
                        return true;
                    }
                    if (j < 7) {
                        if (downLR('r', i, j)) {
                            return true;
                        }
                        if (leftRight('r', i, j)) {
                            return true;
                        }
                    }
                    if (j > 0) {
                        if (downLR('l', i, j)) {
                            return true;
                        }
                        if (leftRight('l', i, j)) {
                            return true;
                        }
                    }
                }
                else if (i == 7) {
                    if (upDown('u', i, j)) {
                        return true;
                    }
                    if (j < 7) {
                        if (upLR('r', i, j)) {
                            return true;
                        }
                        if (leftRight('r', i, j)) {
                            return true;
                        }
                    }
                    if (j > 0) {
                        if (upLR('l', i, j)) {
                            return true;
                        }
                        if (leftRight('l', i, j)) {
                            return true;
                        }
                    }
                }
                else {
                    if (upDown('u', i, j)) {
                        return true;
                    }
                    if (upDown('d', i, j)) {
                        return true;
                    }
                    if (j < 7) {
                        if (leftRight('r', i, j)) {
                            return true;
                        }
                        if (upLR('r', i, j)) {
                            return true;
                        }
                        if (downLR('r', i, j)) {
                            return true;
                        }
                    }
                    if (j > 0) {
                        if (leftRight('l', i, j)) {
                            return true;
                        }
                        if (upLR('l', i, j)) {
                            return true;
                        }
                        if (downLR('l', i, j)) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }
}

bool CheckKing::allDots() {
    for (int i = 0; i < kcols; i++) {
        for (int j = 0; j < krows; j++) {
            if (board[i][j] != '.') {
                return false;
            }
        }
    }
    return true;
}

bool CheckKing::leftRight(char direction, int i, int j) {
    if (direction == 'l') {
        int temp = j;
        while (temp > 0) {
            temp--;
            if (isalpha(board[i][temp])) {
                if (isPiece(board[i][j], 'r', i, temp) || isPiece(board[i][j], 'q', i, temp)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else if (direction == 'r') {
        int temp = j;
        while (temp < 7) {
            temp++;
            if (isalpha(board[i][temp])) {
                if (isPiece(board[i][j], 'r', i, temp) || isPiece(board[i][j], 'q', i, temp)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool CheckKing::upDown(char direction, int i, int j) {
    if (direction == 'u') {
        int temp = i;
        while (temp > 0) {
            temp--;
            if (isalpha(board[temp][j])) {
                if (isPiece(board[i][j], 'r', temp, j) || isPiece(board[i][j], 'q', temp, j)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else if (direction == 'd') {
        int temp = i;
        while (temp < 7) {
            temp++;
            if (isalpha(board[temp][j])) {
                if (isPiece(board[i][j], 'r', temp, j) || isPiece(board[i][j], 'q', temp, j)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool CheckKing::upLR(char direction, int i, int j) {
    if (direction == 'l') {
        int tempI = i;
        int tempJ = j;
        while (tempI > 0 && tempJ > 0) {
            tempI--;
            tempJ--;
            if (isalpha(board[tempI][tempJ])) {
                if (isPiece(board[i][j], 'b', tempI, tempJ) || isPiece(board[i][j], 'q', tempI, tempJ)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else if (direction == 'r') {
        int tempI = i;
        int tempJ = j;
        while (tempI > 0 && tempJ < 7) {
            tempI--;
            tempJ++;
            if (isalpha(board[tempI][tempJ])) {
                if (isPiece(board[i][j], 'b', tempI, tempJ) || isPiece(board[i][j], 'q', tempI, tempJ)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool CheckKing::downLR(char direction, int i, int j) {
    if (direction == 'l') {
        int tempI = i;
        int tempJ = j;
        while (tempI > 0 && tempJ > 0) {
            tempI++;
            tempJ--;
            if (isalpha(board[tempI][tempJ])) {
                if (isPiece(board[i][j], 'b', tempI, tempJ) || isPiece(board[i][j], 'q', tempI, tempJ)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else if (direction == 'r') {
        int tempI = i;
        int tempJ = j;
        while (tempI > 0 && tempJ < 7) {
            tempI++;
            tempJ++;
            if (isalpha(board[tempI][tempJ])) {
                if (isPiece(board[i][j], 'b', tempI, tempJ) || isPiece(board[i][j], 'q', tempI, tempJ)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool CheckKing::knight(int i, int j) {
    if (i >= 2) {
        if (j >= 1) {
            if (isPiece(board[i][j], 'n', i-2, j-1))
                return true;
            }
        if (j <= 6) {
            if (isPiece(board[i][j], 'n', i-2, j+1))
                return true;
            }
    }
    if (i <= 5) {
        if (j >= 1) {
            if (isPiece(board[i][j], 'n', i+2, j-1)) 
                return true;
            }
        if (j <= 6) {
            if (isPiece(board[i][j], 'n', i+2, j+1)) 
                return true;
            }
    }
    if (j >= 2) {
        if (i >= 1) {
            if (isPiece(board[i][j], 'n', i-1, j-2))
                return true;
            }
        if (i <= 6) {
            if (isPiece(board[i][j], 'n', i+1, j-2))
                return true;
            }
    }
    if (j <= 5) {
        if (i >= 1) {
            if (isPiece(board[i][j], 'n', i-1, j+2))
                return true;
            }
        if (i <= 6) {
            if (isPiece(board[i][j], 'n', i+1, j+2))
                return true;
            }
    }
    return false;
}

bool CheckKing::isPiece (char king, char piece, int i, int j) {
    if (isupper(king)) {
        piece = tolower(piece);
    }
    else {
        piece = toupper(piece);
    }
    if (board[i][j] == piece) {
        return true;
    }
    return false;
}

bool CheckKing::pawnCheck(bool isWhite, int i, int j) {
    if (isWhite && i > 0) {
        if (j > 0 && board[i - 1][j - 1] == 'A') {
            return true;
        }
        if (j < 7 && board[i - 1][j + 1] == 'A') {
            return true;
        }
    }
    else if (!isWhite && i < 7) {
        if (j > 0 && board[i + 1][j - 1] == 'a') {
            return true;
        }
        if (j < 7 && board[i + 1][j + 1] == 'a') {
            return true;
        }
    }
    return false;
}