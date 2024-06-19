/*You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Print Yes if you can make nums a strictly increasing array using the above operation and No otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> sieve(int n) {
        vector<int> v(n + 1), ans;
        for (int i=2; i<=sqrt(n); i++) {
            if(!v[i]) {
                for (int j=i*i; j<=n; j+=i) v[j] = 1;
            }
        }
        for (int i=2; i<=n; i++) {
            if (!v[i]) ans.push_back(i);
        }
        return ans;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p = sieve(1000);
        int n = nums.size(), last = nums.back();
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < last) last = nums[i];
            else {
                int pos = lower_bound(p.begin(), p.end(), nums[i]) - p.begin() - 1;
                int f = 0;
                for(int j=0; j<=pos; j++) {
                    if(nums[i] - p[j] < last) {
                        last = nums[i] - p[j];
                        f = 1;
                        break;
                    }
                }
                if(!f) return false;
            }
        }
        return true;
    }
};
int main(){
    int t;
    cin>>t;
    Solution s=Solution();
    vector<bool>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>aux(n);
        for(int i=0;i<n;i++)cin>>aux[i];
        ans.push_back(s.primeSubOperation(aux));
    }
    for(auto it:ans){
        if(it)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}