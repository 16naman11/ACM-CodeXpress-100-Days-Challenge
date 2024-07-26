/*You are given two integers, n and k.

An array of distinct positive integers is called a k-avoiding array if there does not exist any pair of distinct elements that sum to k.

Print the minimum possible sum of a k-avoiding array of length n.*/

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
        int n,k;
        cin>>n>>k;
        int count=0,sum=0;
        for(int i=1;i<=10000;i++){
            int flag=1;
            for(int j=i-1;j>=1;j--){
                if(j+i==k){
                    flag=0;
                    break;
                }
            }
            if(flag){
                sum+=i;
                count++;
            }
            if(count==n){
                break;
            }
        }
        cout<<sum<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
