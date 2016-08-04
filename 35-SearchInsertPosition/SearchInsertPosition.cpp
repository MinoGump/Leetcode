#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = 0;
        int len = nums.size();
        if (len == 0) return 0;
        if (target <= nums[0]) return 0;
        else if (target > nums[len-1]) return len;
        else if (target == nums[len-1]) return len-1;
        int l = 0, r = len - 1;
        int m = (l+r)/2;
        while (l <= r) {
            m = (l+r)/2;
            if (target == nums[m]) return m;
            if (target < nums[m]) r = m-1;
            else if (target > nums[m]) l = m+1;
        }
        m = (l+r)/2;
        if (target < nums[m]) return m-1;
        else if (target > nums[m]) return m+1;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    cout << s.searchInsert(nums,2) << endl;
    system("pause");
    return 0;
}