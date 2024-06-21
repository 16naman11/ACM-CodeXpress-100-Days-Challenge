/*Alice and Bob take turns playing a game, with Alice starting first.

You are given a string num of even length consisting of digits and '?' characters. On each turn, a player will do the following if there is still at least one '?' in num:

Choose an index i where num[i] == '?'.
Replace num[i] with any digit between '0' and '9'.
The game ends when there are no more '?' characters in num.
For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the digits in the second half. For Alice to win, the sums must not be equal.

For example, if the game ended with num = "243801", then Bob wins because 2+4+3 = 8+0+1. If the game ended with num = "243803", then Alice wins because 2+4+3 != 8+0+3. Assuming Alice and Bob play optimally, Print Alice if Alice will win and Bob if Bob will win.*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   bool sumGame(string s) {
        double res = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            res += (i < n / 2 ? 1 : -1) * (s[i] == '?' ? 4.5 : s[i] - '0');
        return res != 0.0;
    }
};
int main(){
    int t;
    cin>>t;
    Solution s=Solution();
    vector<string> ans;
    while(t--){
        string str;
        cin>>str;
        bool awin=s.sumGame(str);
        if(awin){
            ans.push_back("Alice");
        }else{
            ans.push_back("Bob");
        }
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
}