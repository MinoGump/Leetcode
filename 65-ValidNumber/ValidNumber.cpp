#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    enum Type {BLANK, SIGN, DIGIT, POINT, E};
    bool isValid(string s) {
        map<Type, int> *states = new map<Type, int>[9];
        states[0][BLANK] = 0;
        states[0][SIGN] = 1;
        states[0][DIGIT] = 2;
        states[0][POINT] = 3;
        states[1][DIGIT] = 2;
        states[1][POINT] = 3;
        states[2][DIGIT] = 2;
        states[2][POINT] = 4;
        states[2][E] = 5;
        states[2][BLANK] = 8;
        states[3][DIGIT] = 4;
        states[4][DIGIT] = 4;
        states[4][E] = 5;
        states[4][BLANK] = 8;
        states[5][SIGN] = 6;
        states[5][DIGIT] = 7;
        states[6][DIGIT] = 7;
        states[7][DIGIT] = 7;
        states[7][BLANK] = 8;
        states[8][BLANK] = 8;

        int currentState = 0;
        for (char c : s) {
            Type currentType;
            if (c >= '0' && c <= '9') currentType = DIGIT;
            else if (c == '.') currentType = DIGIT;
            else if (c == 'e') currentType = E;
            else if (c == ' ') currentType = BLANK;
            else if (c == '-' || c == '+') currentType = SIGN;
            else return false;
            
            // change state
            if (states[currentState][currentType]) currentState = states[currentState][currentType];
            else return false; 
        }
        
        if (currentState == 2 || currentState == 4 || currentState == 7 || currentState == 8) return true;
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.isValid("2.13e") << endl;
    return 0;
}
