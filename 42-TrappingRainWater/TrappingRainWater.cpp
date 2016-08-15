#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& A) {
        if(A.size() ==0)  
            return 0;  
        int l = 0;  
        int r = A.size()-1;  
        int res = 0;  
        while(l<r)  
        {  
            int min = (A[l] < A[r]) ? A[l] : A[r];  
            if(A[l] == min)  
            {  
                l++;  
                while(l<r && A[l]<min)  
                {  
                    res += min-A[l];  
                    l++;  
                }  
            }  
            else  
            {  
                r--;  
                while(l<r && A[r]<min)  
                {  
                    res += min-A[r];  
                    r--;  
                }  
            }  
        }  
        return res;  
    }
};

int main() {
    Solution s;
    int temp[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(temp, temp+sizeof(temp)/sizeof(int));
    cout << s.trap(height) << endl;
    system("pause");
    return 0;
}