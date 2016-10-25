#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            if (target == matrix[i][0] || target == matrix[i][col-1]) return true;
            if (target > matrix[i][0] && target < matrix[i][col-1]) {
                for (int j = 0; j < col; ++j) {
                    if (target == matrix[i][j]) return true;
                }
            } else if (target < matrix[i][0]) { 
                return false;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    int array[][4] = {{1,3,7,10},{11, 12, 13,14}, {12,21,23,56}};
    vector<vector<int>> matrix;
    for (int i = 0; i < 3; ++i) matrix.push_back(vector<int>(*array+4*i,*array+4*i+4));
    cout << solution.searchMatrix(matrix, 3) << endl;
    return 0;
}
