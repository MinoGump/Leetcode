#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            string res = "", t;
            vector<string> stack;
            stringstream ss(path);
            while (getline(ss, t, '/')) {
                if (t == "" || t == ".") continue;
                if (t == ".." && !stack.empty()) stack.pop_back();
                else if (t != "..") stack.push_back(t);
            }
            for (string s : stack) res += "/" + s;
            return stack.empty() ? "/" : res;
        }
};

int main() {
    Solution solution;
    cout << solution.simplifyPath("/home/mino/./../rasd/../rt/") << endl;
    return 0;
}
