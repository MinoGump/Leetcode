#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) return true;
        if (p.size() == 0) return false;

        // initialize the match array
        bool match[s.size()+1] = {false};
        match[0] = true;

        for (int j = 0; j < p.size(); j++) {
            if (p[j] == '*') {
                int i = 0;
                while (i <= s.size() && !match[i]) {
                    i++;
                }
                for (; i <= s.size(); i++) {
                    match[i] = true;
                }
            } else {
                for (int i = s.size()-1; i >= 0; i--) {
                    if (match[i] && (p[j] == '?' || s[i] == p[j])) {
                        match[i+1] = true;
                    } else {
                        match[i+1] = false;
                    }
                }
            }
            match[0] = match[0] && p[j] == '*';  
        }
        return match[s.size()];
    }
};

int main() {
    Solution solution;
    string s = "aa", p = "a";
    cout << solution.isMatch(s, p) << endl;
    system("pause");
    return 0;
}