#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.size() == 0) return vector<int>(1,1);
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            if (carry == 1) {
                digits[i] = (digits[i] + carry);
                carry = digits[i] / 10;
                digits[i] %= 10;
            } else {
                break;
            }
        }
        if (carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution solution;
    int digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ds(digits, digits+sizeof(digits)/sizeof(int));
    vector<int> res = solution.plusOne(ds);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
