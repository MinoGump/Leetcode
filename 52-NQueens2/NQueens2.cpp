#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        totalSolutions = 0;
        vector<int> solution(n, -1);
        helper(solution, 0);
        return totalSolutions;
    }
    
    void helper(vector<int> &solution, int row) {
        int n = solution.size();
        if (row == n) {    // find the solution
            ++totalSolutions;
            return ;
        } else {
            for (int col = 0; col < n; ++col) {
                if (isValid(solution, row, col)) {
                    solution[row] = col;
                    helper(solution, row+1);
                    solution[row] = -1;
                }
            }
        }
    }
    
    bool isValid(vector<int> solution, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == solution[i] || abs(row-i) == abs(col-solution[i])) return false;
        }
        return true;
    }
private:
    int totalSolutions;
};


int main() {
    Solution solution;
    cout << solution.totalNQueens(8) << endl;
    return 0;
}
