#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> temp(len1+len2, 0);
        int k = len1 + len2 - 2;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                temp[k-i-j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        int carry = 0;
        for (int i = 0; i < len1+len2; i++) {
            temp[i] += carry;
            carry = temp[i] / 10;
            temp[i] %= 10;
        }
        int i = k+1;
        while (temp[i] == 0) i--;
        if (i < 0) return "0";
        string res;
        for (; i >= 0; i--) {
            res.push_back(temp[i] + '0');
        }
        return res;
    }
};

int main() {
    Solution s;
    string num1 = "2312", num2 = "321";
    cout << s.multiply(num1, num2) << endl;
    system("pause");
    return 0;
}