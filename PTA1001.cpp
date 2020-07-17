#include<iostream>
using namespace std;

int main()
{
    int n1, n2,count;
    int n[8];
    count = 0;
    cin >> n1 >> n2;
    int a = n1 + n2;
    if(a == 0) {
        cout << "0";
    }
    else{
        int neg = 0;
        if(a < 0) {
            a = -a;
            neg = 1;
        }
        while(a > 0) {
            n[count] = a%10;
            a=a/10;
            count++;
        }
        if(neg)
            cout << "-";
        count--;
        for(int i = count; i >= 0; i--) {

            cout<<n[i];
            if(i%3 == 0 && i >0)
                cout << ",";
        }
    }
    

    return 0;
}