#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>    // std::sort
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        int size = candidates.size();
        sort(candidates.begin(), candidates.end());
        if (target < candidates[0] || size == 0) return res;
        vector<int> item;
        helper(candidates, 0, target, item, res);
        return res;
    }

    void helper(vector<int> candidates, int start, int target, vector<int> item, vector<vector<int> > &res) {
        if (target < 0) return;
        if (target == 0) {
            vector<int> tempItem(item);
            res.push_back(tempItem);
            return ;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i-1]) continue;
            item.push_back(candidates[i]);
            helper(candidates, i, target-candidates[i], item, res);
            item.pop_back();
        }
    }
};

int main() {
    Solution s;
    int nums[] = {2, 3, 5, 7};
    int target = 7;
    vector<int> candidates(nums, nums+sizeof(nums)/sizeof(int));
    vector<vector<int> > res = s.combinationSum(candidates, target);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
    system("pause");
    return 0;
}