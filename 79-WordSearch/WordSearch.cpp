#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty()) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(findWord(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool findWord(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string &word, int index) {
        if(index==word.size()) return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col] || board[row][col]!=word[index]) 
            return false;
            
        visited[row][col] = true;
        if(findWord(board, visited, row-1, col, word, index+1)) return true;  
        if(findWord(board, visited, row+1, col, word, index+1)) return true;
        if(findWord(board, visited, row, col-1, word, index+1)) return true;
        if(findWord(board, visited, row, col+1, word, index+1)) return true;
        visited[row][col] = false;
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board(3, vector<char>(4, ' '));
    char array[][4] = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j)
            board[i][j] = array[i][j];
    }
    cout << solution.exist(board, "ABCCED") << endl;
    return 0;
}
