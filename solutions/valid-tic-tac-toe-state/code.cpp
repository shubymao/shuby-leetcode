#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validTicTacToe(vector<string>& board) {
        int diff = getDiff(board);
        auto wins = getWins(board);
        if (diff < 0 || diff >= 2) return false;
        if (wins.first && wins.second) return false;
        if (wins.first && diff == 0) return false;
        if (wins.second && diff != 0) return false;
        return true;
    }

    int getDiff(vector<string>& board) {
        int diff = 0;
        for (auto row : board) {
            for (auto cell : row) {
                if (cell == 'X')
                    diff++;
                else if (cell == 'O')
                    diff--;
            }
        }
        return diff;
    }

    pair<int, int> getWins(vector<string>& board) {
        int xWin = 0;
        int oWin = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == 'X')
                    xWin++;
                else if (board[i][0] == 'O')
                    oWin++;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == 'X')
                    xWin++;
                else if (board[0][i] == 'O')
                    oWin++;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[1][1] == 'X')
                xWin++;
            else if (board[1][1] == 'O')
                oWin++;
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            if (board[1][1] == 'X')
                xWin++;
            else if (board[1][1] == 'O')
                oWin++;
        }
        return make_pair(xWin, oWin);
    }
};