#include <iostream>
#include <vector>

using namespace std;

/*
   利用DFS，每次选择rest个数字，rest从0到n，这样就是真子集了
   每次选择rest个数字后，进行start到n-rest的选择，每次添加到persol里面，进行递归，再pop掉数字，当rest为0时插入到最终集合中
*/

class Solution {
private:
    vector<vector<int>> sols;
    int n;
    vector<int> numbers;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        numbers = nums;
        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> persol;
            helper(0, i, persol);
        }
        return sols;
    }
    
    void helper(int start, int rest, vector<int> persol) {
        if (rest == 0) {
            sols.push_back(persol);
            return ;
        }
        for (int i = start; i <= n - rest; ++i) {
            persol.push_back(numbers[i]);
            helper(i+1, rest-1, persol);
            persol.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int array[] = {1,2,3,6,5,8,4,0};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    vector<vector<int>> res = solution.subsets(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout << "],";
    }
    cout << endl;
    return 0;
}
