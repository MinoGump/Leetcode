#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Solution {
   public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string res = "1";
        for (int i = 2; i <= n; i++) {
            char curChar = res[0];
            int times = 1;
            string tmpstr;
            res.push_back('#');
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == curChar) times++;
                else {
                    ostringstream ss;
                    ss << times;
                    tmpstr += ss.str();
                    tmpstr.push_back(curChar);
                    curChar = res[j];
                    times = 1;
                }
            }
            res = tmpstr;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 6;
    cout << s.countAndSay(n) << endl;
    system("pause");
    return 0;
}