#include <iostream>

using namespace std;

class Solution {
  public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double last = 0;
        double res = 1;
        while (last != res) {
            last = res;
            res = (res + x/res) / 2;
        }
        return int(res);
    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(2135) << endl;
    return 0;
}
