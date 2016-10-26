#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

    void sortColors(vector<int>& nums) {

        int lastLeft = 0, lastRight = nums.size()-1;

        for (int i = 0; i < nums.size(); ++i) {

            if (nums[i] == 0) {

                if (i > lastLeft) {

                    swap(nums[i], nums[lastLeft]);

                    --i;

                }

                ++lastLeft;

            } else if (nums[i] == 2) {

                if (i < lastRight) {

                    swap(nums[i], nums[lastRight]);

                    --i;

                }

                --lastRight;

            }

        }

    }

    

    void swap(int &a, int &b) {

        int temp = a;

        a = b;

        b = temp;

    }

};

int main() {
    Solution solution;
    int array[] = {1,2,1,0,0,2,1,0,2,2,1,0,2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    solution.sortColors(nums);
    for(auto v : nums) {cout<< v << " ";};
    return 0;
}
