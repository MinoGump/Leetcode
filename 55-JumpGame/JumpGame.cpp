#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
   	bool canJump(vector<int> &nums) {
		int size = nums.size();
		if (size == 0) return false;
		bool flag[][size] = {false};
		bool result = false;
		result = dfs(nums, 0, size-1);	
		return result;	
	}

	bool dfs(vector<int> &nums, int start, int end) {
		if (nums[start] >= end - start) return true;
		for (int i = 1; i <= nums[start]; i++) {
			if (dfs(nums, start+i, end)) {
			      return true;
			}
		}
		return false;
	}
};

int main() {
    Solution solution;
	int array[] = {3, 2, 1, 0, 4};
    	vector<int> nums(array, array+5);
	cout << solution.canJump(nums) << endl;
    return 0;
}
