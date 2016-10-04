#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
vector<vector<int> > spiralMatrix(int n) {
    vector<vector<int> > eresult;
    if (n == 0) return eresult;
    vector<vector<int> > result(n, vector<int>(n, 0));
    int cycle = (n+1)/2, a=n;  // cycle是要循环的次数，a是当前环的长度
    for (int i = 0, c = 1; i < cycle; i++, a-=2) {
        if (a == 1) {
            result[n/2][n/2] = c++;
        } else {
            for (int j = i; j < i + a - 1; j++) {
                result[i][j] = c++;
            }
    	    for (int j = i; j < i + a - 1; j++) {
                result[j][a+i-1] = c++;
            }
            for (int j = i + a - 1; j > i; j--) {
                result[i+a-1][j] = c++;
            }
            for (int j = i + a - 1; j > i; j--) {
                result[j][i] = c++;
            }
        }
    }
    return result;
}
};

int main() {
    Solution solution;
    vector<vector<int> > result;
    result = solution.spiralMatrix(3);
    for (int i = 0; i < result.size(); i++) {
       for (int j = 0; j < result[i].size(); j++) {
           cout << result[i][j] << " ";
       }
       cout << endl;
    }
    return 0;
}
