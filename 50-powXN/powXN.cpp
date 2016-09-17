#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {  
        if(n==0)return 1;  
        if(n==1)return x;  
        double temp=pow(x,abs(n/2));  
        if(n>0)  
        {  
            if(n&1)return temp*temp*x;  
            else return temp*temp;  
        }  
        else   
        {  
            if(n&1)return 1.0/(temp*temp*x);  
            else return 1.0/(temp*temp);  
        }  
    }  
};

int main() {
    Solution solution;
    cout << solution.myPow(142.312, 20) << endl;
    system("pause");
    return 0;
}