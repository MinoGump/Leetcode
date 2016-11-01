#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) return nums.size();

        int len = nums.size();
        int newIndex = 1;
        for (int i = 2; i < len; ++i) {
            if (nums[i] != nums[newIndex] || nums[i] != nums[newIndex - 1]) {
                ++newIndex;
                nums[newIndex] = nums[i];
            }
        }

        return newIndex + 1;
    }
};

int main() {
    Solution solution;
    int array[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums(array+0, array+sizeof(array)/sizeof(int));
    cout << solution.removeDuplicates(nums) << endl;
    return 0;
}
