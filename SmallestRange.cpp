#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[N-1] - nums[0];

        for (int i = 0; i < nums.size() - 1; ++i) {
            int a = nums[i], b = nums[i+1];
            int high = max(nums[N-1] - k, a + k);
            int low = min(nums[0] + k, b - k);
            ans = min(ans, high - low);
        }
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    vector<int> ans;
    Solution s=Solution();
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> aux(n);
        for(int i=0;i<n;i++)cin>>aux[i];
        ans.push_back(s.smallestRangeII(aux,k));
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
}