#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            string temp = a;
            a = b;
            b = temp;
        }
        int lena = a.length(), lenb = b.length();
        int carry = 0, i, j;
        for (i = lenb-1, j = lena-1; i >= 0; --i, --j) {
            int temp = ((a[j] - '0') + (b[i] - '0') + carry);
            carry = temp / 2;
            a[j] = (temp % 2) + '0';
        }
        if (carry == 1) {
            if (j == -1) return "1" + a;
            else {
                while (a[j] == '1') {
                    a[j] = '0';
                    --j;
                }
                if (j == -1) return "1" + a;
                else a[j] = '1';
            }
        }
        return a;
    }
};

int main() {
    Solution solution;
    string a = "11", b = "1";
    cout << solution.addBinary(a, b) << endl;
    return 0;
}
