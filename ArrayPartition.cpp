/*Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Print the maximized sum.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[2*n],i=2*n;
        while(i--){
            cin>>a[i];
        }
        qsort(a, 2*n, sizeof(int), compare);

        int sum=0;
        for(int i=0;i<2*n;i+=2){
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
