#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:

    string getPermutation(int n, int k) {
        int fn = factorial(n);        
        if (k > fn) return "";
        string candidate = string("123456789").substr(0, n);
        string res(n, ' ');
        for (int i = 0; i < n; i++) {
            fn /= (n - i);
            int index = (k - 1)/fn;
            res[i] = candidate[index];
            candidate.erase(index, 1);
            k -= index * fn;
        }
        return res;
    }

    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n, k;
    cin >> n >> k;
    cout << solution.getPermutation(n,k) << endl;
    return 0;
}
