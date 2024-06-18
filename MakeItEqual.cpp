/*You are given a 0-indexed integer array nums and an integer k.

A subarray is called equal if all of its elements are equal. Note that the empty subarray is an equal subarray.

Print the length of the longest possible equal subarray after deleting at most k elements from nums.

A subarray is a contiguous, possibly empty sequence of elements within an array.*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int mid,int k,vector<int>&nums)
    {
         int i=0,j=0;
          unordered_map<int ,int>check;
        while(j<nums.size()){
            if(check[nums[j]]+1>=mid)return true;
            check[nums[j]]+=1;
            if(j>= k+mid-1){
                check[nums[i]]-=1;
                i+=1;
            }
            j++;
        }
        return false;
    }
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        int s= 1 ,e = nums.size(),ans=0;
        while(s<=e)
        {
            int mid = (e-s)/2+s;
            if(helper(mid,k,nums))
            {
                ans=mid,s = mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    vector<int>ans;
    Solution s=Solution();
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> aux(n);
        for(int i=0;i<n;i++)cin>>aux[i];
        ans.push_back(s.longestEqualSubarray(aux,m));
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
}