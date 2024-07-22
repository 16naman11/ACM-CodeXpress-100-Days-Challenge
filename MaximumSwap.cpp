/*You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Print the maximum valued number you can get.*/

#include<bits/stdc++.h>

using namespace std;

class Solution {

public:

int isMax(int maxi,int i,int j, vector<int>v){

    int num=0;

    for(int i=0;i<v.size();i++){

        num=num*10+v[i];

    }

    if(num>maxi) return num;

    return maxi;

}

    int maximumSwap(int num) {

        int n;

        vector<int> v;

        int num1=num;

        while(num1){

            v.push_back(num1%10);

            num1=num1/10;

        }

        reverse(v.begin(),v.end());

        n=v.size();

        int maxi=INT_MIN;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                swap(v[i],v[j]);

                if(isMax(maxi,i,j,v)>maxi){

                    maxi=isMax(maxi,i,j,v);

                }

                swap(v[i],v[j]);

            }

        }

        return maxi;

    }

};

int main(){

    int t;

    Solution s=Solution();

    cin>>t;

    vector<int> ans;

    while(t--){

        int n;

        cin>>n;

        ans.push_back(s.maximumSwap(n));

    }

    for(auto it:ans)cout<<it<<endl;

}
