#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int width = grid.size(), height = grid[0].size();
        int *sum = new int[height];
        sum[0] = grid[0][0];
        // 动态规划，每次取最小值
        for (int i = 0; i < width; ++i) {
            if (i == 0) {
                for (int j = 1; j < height; ++j) sum[j] = sum[j-1] + grid[i][j];
            } else {
                for (int j = 0; j < height; ++j) {
                    if (j == 0) sum[0] = sum[0] + grid[i][j];
                    else if (j > 0) sum[j] = (sum[j] > sum[j-1]) ? sum[j-1] + grid[i][j] : sum[j] + grid[i][j];
                }
            }
        }
        return sum[height - 1];
    }
};

int main() {
    Solution solution;
    int g[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<vector<int> > grid;
    for (int i = 0; i < 4; i++)
        grid.push_back(vector<int>(g+i*3,g+i*3+3));
    cout << solution.minPathSum(grid) << endl;
    return 0;
}
