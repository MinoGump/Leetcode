#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0 && nums[i] <= len) {
                if (nums[nums[i]-1] != nums[i]) {
                    swap(nums[i], nums[nums[i]-1]);
                    i--;
                }
            }
        }
        for (int i = 0; i < len; i++) {
           if (nums[i] != i+1) return i+1;
        }
        return len+1;
    }
};

int main() {
    Solution s;
    int num[] = {3, 4, -1, 1};
    vector<int> nums(num, num + sizeof(num)/sizeof(int));
    cout << s.firstMissingPositive(nums) << endl;
    system("pause");
    return 0;
}