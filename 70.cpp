#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int sum = 0;
        int f1 = 1;
        int f2 = 2;
        for(int i = 3; i <= n; i++) { 
            sum = f1+f2;
            f1 = f2;
            f2 = sum;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    int x = s.climbStairs(n);
    cout << x;
    return 0;
}
