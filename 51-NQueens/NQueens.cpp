#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> perResult(n, -1);
        helper(perResult, 0);
        return result;
    }

    void helper(vector<int> &perResult, int row) {
        int n = perResult.size();
        if (row == n) {   // 如果达到n个则添加到输出结果内
            vector<string> tmpstr(n, string(n, '.'));
            for (int i = 0; i < n; ++i)
                tmpstr[i][perResult[i]] = 'Q';
            result.push_back(tmpstr);
            return ;
        } else {     // 否则对该行按列进行尝试
            for (int col = 0; col < n; ++col) {
                if (isValid(perResult, row, col)) {
                    perResult[row] = col;
                    helper(perResult, row+1);
                    perResult[row] = -1;
                }
            }
        }
    }
    
    bool isValid(vector<int> per, int row, int col) {
        // 只需要检测前row行的每个皇后是否与当前皇后矛盾
        for (int i = 0; i < row; ++i) {
            // per[i] == col : 列相同       abs(row-i) == abs(col-per[i]) : 斜线相同
            if (per[i] == col || abs(row-i) == abs(col-per[i])) return false;
        }
        return true;
    }
private:
    vector<vector<string> > result;
};

int main() {
    Solution solution;
    vector<vector<string> > res = solution.solveNQueens(8);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "," << endl;
        }
        cout << "]," << endl;
    } 
    cout << "]" << endl;
    return 0;
}
