#include <iostream>

using namespace std;

class Solution {

public:

    int uniquePaths(int m, int n) {

        if (m > n) {

            int temp = m;

            m = n;

            n = temp;

        }

        int times = 1;

        long long fenzi = 1, fenmu = 1;

        for (int total = m + n - 2; times <= m-1; times++, total--) {

            fenzi *= total;

            fenmu *= times;

        }

        return (int)(fenzi/fenmu);

    }

};

int main() {
    Solution solution;
    int m, n;
    cin >> m >> n;
            cout << solution.uniquePaths(m, n) << endl;
    return 0;
}
