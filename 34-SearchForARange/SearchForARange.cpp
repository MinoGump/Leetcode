#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {

    public:
     vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0) return res;
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] > target || nums[r] < target) return res;
        int m = (l+r)/2;
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] == target) {
                break;
            } else {
                if (nums[m] < target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        if (l > r) return res;
        m = (l + r) / 2;
        l = m;
        r = m;
        while (nums[l] == target && l >= 0) l--;
        if (nums[l+1] == target) res[0] = l+1;
        while (nums[r] == target && r < nums.size()) r++;
        if (nums[r-1] == target) res[1] = r-1;
        return res;
    }

};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    vector<int> res = s.searchRange(nums, 8);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    system("pause");
    return 0;
}