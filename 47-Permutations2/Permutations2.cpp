#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &result, vector<int> &num, int start)
    {
        if(start >= num.size()) // >= ">"also should be put in, for the last ele.
        {
            result.push_back(num);
            return;
        }
        for(int i = start; i < num.size(); i++)
        {
            if(i != start && num[i] == num[i-1]) continue; //culling
            std::swap(num[i], num[start]);
            dfs(result, num, start+1);
            std::swap(num[i], num[start]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        vector<vector<int> > result;
        std::sort(num.begin(), num.end());
        dfs(result, num, 0);
        return vector<vector<int> >(result.begin(), result.end());
    }
};

int main() {
    Solution s;
    int temp[] = {1, 2, 1};
    vector<int> input(temp, temp+sizeof(temp)/sizeof(int));
    vector<vector<int> > res = s.permuteUnique(input);
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
    system("pause");
    return 0;
}