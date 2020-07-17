#include <iostream>
#include <string> 
using namespace std;

/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if(s1.length() + s2.length() != s3.length())
    		return false;
    	
		if(s1.length() == 0) {
    		if(s2.compare(s3) == 0)
    			return 1;
    		return 0;
    	}
    	if(s2.length() == 0) {
    		if(s1.compare(s3) == 0)
    			return 1;
    		return 0;
    	}
    	
    	if(s1[s1.length()-1] != s3[s3.length()-1] && s2[s2.length()-1] != s3[s3.length()-1])
    		return false;
    	if(s1[s1.length()-1] == s3[s3.length()-1] && s2[s2.length()-1] != s3[s3.length()-1]) {
    		return(isInterleave(s1.substr(0,s1.length()-1),s2,s3.substr(0,s3.length()-1)));
    	}
    	else if(s1[s1.length()-1] != s3[s3.length()-1] && s2[s2.length()-1] == s3[s3.length()-1]) {
    		return(isInterleave(s1,s2.substr(0,s2.length()-1),s3.substr(0,s3.length()-1)));
    	}
    	else
    		return(
			isInterleave(s1,s2.substr(0,s2.length()-1),s3.substr(0,s3.length()-1)) |
			isInterleave(s1.substr(0,s1.length()-1),s2,s3.substr(0,s3.length()-1))
			);

    }
};
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if(s1.length() + s2.length() != s3.length())
    		return false;
    		
        int** a = new int*[s1.length()+1];
        for(int i = 0; i < s1.length()+1; i++) {
            a[i] = new int[s2.length()+1];
        }
        
        a[0][0] = 1;
        for(int i = 1; i < s1.length()+1; i++) {
            a[i][0] = a[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for(int i = 1; i < s2.length()+1; i++) {
            a[0][i] = a[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        
        for(int i = 1; i < s1.length()+1; i++) {
        	for(int j = 1; j < s2.length()+1; j++) {
        		a[i][j] = (a[i-1][j] && (s1[i-1] == s3[i+j-1])) || (a[i][j-1] && (s2[j-1] == s3[i+j-1]));
        	}
        }
        
        /*
        for(int i = 1; i < s1.length()+1; i++) {
        	for(int j = 1; j < s2.length()+1; j++) {
        		cout << a[i][j];
        	}
        	cout <<endl;
        }
        */
        
        int ans = a[s1.length()][s2.length()];

        for(int i = 0; i < s1.length()+1; i++) {
            delete []a[i];
        }
        return ans;
    }
};

int main()
{
    string a,b,c;
    Solution solution;
    cin >> a >> b >> c;
    cout << solution.isInterleave(a,b,c) <<endl;
    return 0;
}
