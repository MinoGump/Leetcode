#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        if (strs.size() == 0) return result;
        map<string, int> map;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (map.find(temp) != map.end()) {
                result[map[temp]].push_back(strs[i]);
            } else {
                vector<string> per;
                per.push_back(strs[i]);
                result.push_back(per);
                map[temp] = result.size() - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs(s, s+6);
    vector<vector<string> > res = solution.groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}