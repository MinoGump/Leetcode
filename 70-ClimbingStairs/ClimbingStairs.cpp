#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 1; i <= n; i++) {
            int temp = a;
            a = b;
            b = b + temp;
        } 
        return b;
    }
};

int main() {
    Solution solution;
    cout << solution.climbStairs(19) << endl;
    return 0;
}
