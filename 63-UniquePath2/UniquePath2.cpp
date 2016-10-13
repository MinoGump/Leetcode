#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        int *res = new int[obstacleGrid[0].size()];
        res[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 1) {
                    res[j] = 0;
                } else {
                    if (j > 0) res[j] += res[j-1];
                }
            }
        }
        return res[obstacleGrid[0].size()-1];
    }
};

int main() {
    Solution solution;
    int obstacle[] = {0,0,0,0,1,0,0,0,0};
    vector<vector<int> > obstacleGrid;
    for (int i = 0; i < 3; i++) {
        obstacleGrid.push_back(vector<int>(obstacle+3*i, obstacle+3*i+3));
    }
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
