/*You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2^i + num2 from num1.

Print the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, print -1.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countBits(long long num) 
{ 
    int count = 0; 
    while(num>0) 
    { 
        count += num & 1; 
        num >>= 1; 
    } 
    return count; 
} 
int minOperation(int num1, int num2) 
{ 
    if(num1<num2) 
    { 
        return -1; 
    } 
    for(int i=0; i<= 40; i++) 
    { 
        long long diff = num1 - (num2) * 1LL*i; 
        int bits = countBits(diff); 
        if(bits<=i && i<=diff) 
        { 
            return i; 
        } 
    } 
    return -1; 
} 

int main() {
    int T;
    cin>>T;
    
    int j=0;
    while(j<T)
    {
        int num1 , num2;
        cin>>num1>>num2;
        
        int ans = minOperation(num1 , num2);
        cout<<ans<<endl;
        j++;
    }
    return 0;
}