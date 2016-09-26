#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > allPer;
        if(num.empty()) return allPer;
        sort(num.begin(),num.end());
        vector<int> per;
        vector<bool> used(num.size(),false);
        findPerUniq(num, used, per, allPer);
        return allPer;
    }
    
    void findPerUniq(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int> > &allPer) {
        if(per.size()==num.size()) {
            allPer.push_back(per);
            return;
        }
        
        for(int i=0; i<num.size(); i++) {
            if(used[i]) continue;
            if(i>0 && num[i]==num[i-1] && !used[i-1]) continue;
            used[i] = true;
            per.push_back(num[i]);
            findPerUniq(num, used, per, allPer);
            per.pop_back();
            used[i] = false;
        }
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