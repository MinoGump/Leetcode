#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int width = matrix.size();
        if (width == 0) return ;
        int height = matrix[0].size();
        if (height == 0 || height != width) return ;
        for (int i = 0; i < width / 2; i++) {
            for (int j = 0; j < height / 2; j++) {
                int second = matrix[j][height - 1 - i];
                matrix[j][height - 1 - i] = matrix[i][j];
                int third = matrix[width - 1 - i][height - 1 - j];
                matrix[width - 1 - i][height - 1 - j] = second;
                int fourth = matrix[width - 1 - j][i];
                matrix[width - 1 - j][i] = third;
                matrix[i][j] = fourth;
            }
        }
        if (width % 2 == 1) {
            int middle = width / 2;
            for (int i = 0; i < middle; i++) {
                int second = matrix[middle][height - 1 - i];
                matrix[middle][height - 1 - i] = matrix[i][middle];
                int third = matrix[width - 1 - i][middle];
                 matrix[width - 1 - i][middle] = second;
                int fourth = matrix[middle][i];
                matrix[middle][i] = third;
                matrix[i][middle] = fourth;
            }
        }
    }
};

int main() {
    Solution solution;
    int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(m, m+3));
    matrix.push_back(vector<int>(m+3, m+6));
    matrix.push_back(vector<int>(m+6, m+9));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            printf("%4d", matrix[i][j]);
        }
        cout << endl;
    }
    solution.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            printf("%4d", matrix[i][j]);
        }
        cout << endl;
    }
    system("pause");
    return 0;
}