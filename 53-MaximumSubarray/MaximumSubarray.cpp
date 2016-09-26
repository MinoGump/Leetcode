#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int result = 0;
        if (nums.size() == 0) return result;
        int sum = nums[0];
        result = sum;
        for (int r = 1; r < nums.size(); r++) {
            sum = (nums[r] > nums[r] + sum) ? nums[r] : nums[r] + sum;
            result = (result > sum) ? result : sum;
        }
        return result;
    }
};


int main() {
    Solution s;
    int num[] = {3, 4, -1, 1};
    vector<int> nums(num, num + sizeof(num)/sizeof(int));
    cout << s.maxSubArray(nums) << endl;
    system("pause");
    return 0;
}