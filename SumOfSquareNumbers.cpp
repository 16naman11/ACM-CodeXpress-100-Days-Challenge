/*Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int flag=0;
        int left = 0;
        int right = sqrt(n);

        while (left <= right) {
            int currentSum = left * left + right * right;

            if (currentSum == n) {
                cout<<"yes"<<endl;
                flag=1;
                break;
            } else if (currentSum < n) {
                left++;
            } else {
                right--;
            }
        }

        if(flag==0)
            cout<<"no"<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
