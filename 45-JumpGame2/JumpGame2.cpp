#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+nums[i]);
        }

        return ret;
    }
};

int main() {
    Solution solution;
    int array[] = {2,3,1,1,4};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout << solution.jump(nums) << endl;
    return 0;
}
