#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return ;
        helper(board, 0, 0);
    } 

    bool helper(vector<vector<char> > &board, int i, int j) {
        if (i == 9) {
            return true;
        }
        if (j >= 9) {
            return helper(board, i+1, 0);
        }
        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; k++) {
                board[i][j] = (char)(k + '0');
                if (isValid(board, i, j)) {
                    if (helper(board, i, j+1)) return true;
                }
                board[i][j] = '.';
            }
        } else {
            return helper(board, i, j+1);
        }
        return false;
    }

    bool isValid(vector<vector<char> > &board, int x, int y) {
        for (int i = 0; i < 9; i++) {
            if (x != i && board[i][y] == board[x][y]) return false; 
        }
        for (int j = 0; j < 9; j++) {
            if (y != j && board[x][j] == board[x][y]) return false;
        }
        for (int row = x/3*3; row < x/3*3+3; row++) {
            for (int col = y/3*3; col < y/3*3+3; col++) {
                if ((x != row || y != col) && board[row][col] == board[x][y]) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    char *temp[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++) {
        vector<char> t(temp[i], temp[i]+9*sizeof(char));
        board.push_back(t);
    }
    s.solveSudoku(board);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    system("pause");
    return 0;
}