#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();
        int** a = new int*[w1+1];
        for(int i = 0; i < w1+1; i++) {
            a[i] = new int[w2+1];
        }

        for(int i = 0; i < w1+1; i++) {
            a[i][0] = i;
        }
        for(int i = 0; i < w2+1; i++) {
            a[0][i] = i;
        }
        for(int i = 1; i < w1+1; i++) {
            for(int j = 1; j < w2+1; j++) {
                if(word1[i-1] == word2[j-1])
                    a[i][j] = a[i-1][j-1];
                else {
                    a[i][j] = min(a[i-1][j],a[i][j-1]);
                    a[i][j] = min(a[i-1][j-1], a[i][j]) + 1;
                }
            }
        }
        int ans = a[w1][w2];

        for(int i = 0; i < w1; i++) {
            delete []a[i];
        }
        return ans;
        
    }
};

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    Solution s;
    int n = s.minDistance(s1, s2);
    cout << n;
    return 0;
}