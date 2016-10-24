#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        vector<int> vx, vy;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    vx.push_back(i);
                    vy.push_back(j);
                }
            }
        }
        for (int i = 0; i < vx.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[vx[i]][j] = 0;
            }
            for (int j = 0; j < matrix.size(); ++j) {
                matrix[j][vy[i]] = 0;
            }
        }
    }
};

int main() {
    Solution solution;
    int array[] = {1,2,0,2,10,0,0,1,2,2,3,1};
    vector<vector<int> > matrix;
    for (int i = 0; i < 4; ++i) matrix.push_back(vector<int>(array+3*i, array+3*i+3));
    solution.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
