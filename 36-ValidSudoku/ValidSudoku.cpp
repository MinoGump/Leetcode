#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int height = board.size();
        if (height != 9) return false;

        int exist[9] = {0};

        for (int i = 0; i < height; i++) {
            int width = board[i].size();
            if (width != 9) return false;
            memset(exist, 0, sizeof(exist));
            for (int j = 0; j < width; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    if (exist[board[i][j] - '1'] != 0) return false;
                    else exist[board[i][j] - '1'] = 1;
                } else if (board[i][j] != '.') {
                    return false;
                }
            }
        }

        for (int i = 0; i < height; i++) {
            memset(exist, 0, sizeof(exist));
            for (int j = 0; j < height; j++) {
                if (board[j][i] >= '1' && board[j][i] <= '9') {
                    if (exist[board[j][i] - '1'] != 0) return false;
                    else exist[board[j][i] - '1'] = 1;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                memset(exist, 0, sizeof(exist));
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[3*i+k][3*j+l] >= '1' && board[3*i+k][3*j+l] <= '9') {
                            if (exist[board[3*i+k][3*j+l] - '1'] != 0) return false;
                            else exist[board[3*i+k][3*j+l] - '1'] = 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    char first[] = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    char second[] = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    char third[] = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    char fourth[] = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    char fifth[] = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    char sixth[] = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    char seventh[] = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    char eighth[] = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    char ninth[] = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    vector<char> firstv(first, first+sizeof(first)/sizeof(char));
    vector<char> secondv(second, second+sizeof(second)/sizeof(char));
    vector<char> thirdv(third, third+sizeof(third)/sizeof(char));
    vector<char> fourthv(fourth, fourth+sizeof(fourth)/sizeof(char));
    vector<char> fifthv(fifth, fifth+sizeof(fifth)/sizeof(char));
    vector<char> sixthv(sixth, sixth+sizeof(sixth)/sizeof(char));
    vector<char> seventhv(seventh, seventh+sizeof(seventh)/sizeof(char));
    vector<char> eighthv(eighth, eighth+sizeof(eighth)/sizeof(char));
    vector<char> ninthv(ninth, ninth+sizeof(ninth)/sizeof(char));
    vector<vector<char> > nums;
    nums.push_back(firstv);
    nums.push_back(secondv);
    nums.push_back(thirdv);
    nums.push_back(fourthv);
    nums.push_back(fifthv);
    nums.push_back(sixthv);
    nums.push_back(seventhv);
    nums.push_back(eighthv);
    nums.push_back(ninthv);
    cout << s.isValidSudoku(nums) << endl;
    system("pause");
    return 0;
}