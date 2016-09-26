#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.empty()) return res;
        res.push_back(vector<int> (1,nums[0]));

        for (int i = 1; i < nums.size(); i++) {
            int n = res.size();
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < res[j].size(); k++) {
                    vector<int> per = res[j];
                    per.insert(per.begin() + k, nums[i]);
                    res.push_back(per);
                }
                res[j].push_back(nums[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int temp[] = {1, 2, 3};
    vector<int> input(temp, temp+sizeof(temp)/sizeof(int));
    vector<vector<int> > res = s.permute(input);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
    system("pause");
    return 0;
}