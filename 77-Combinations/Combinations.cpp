#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> sols;
    int length;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> persol;
        length = n;
        helper(1, k, persol);
        return sols;
    }
    
    void helper(int start, int rest, vector<int> persol) {
        if (rest == 0) {
            sols.push_back(persol);
            return ;
        }
        for (int i = start; i <= length - rest + 1; ++i) {
            persol.push_back(i);
            helper(i+1, rest-1, persol);
            persol.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> res = solution.combine(6,4);
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout <<"], ";
    }
    cout << endl;
    return 0;
}
