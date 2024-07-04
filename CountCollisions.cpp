/*There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
When a moving car collides with a stationary car, the number of collisions increases by 1.
After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

Print the total number of collisions that will happen on the road.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int countCollisions(string directions) {
        stack<char> st;
        int cnt = 0;
        for(char ch : directions){
            if(ch == 'R'){
                st.push('R');
            }else if(ch == 'S'){
                while(st.size() > 0 && st.top() == 'R'){
                    st.pop();
                    cnt++;
                }
                st.push('S');
            }else{
                bool colsn = false;
                if(st.size() > 0 && st.top() == 'R'){
                    cnt+=2;
                    st.pop();
                    colsn = true;
                }else if(st.size() > 0 && st.top() == 'S'){
                    cnt++;
                    colsn = true;
                }
                while(st.size() > 0 && st.top() == 'R'){
                    st.pop();
                    cnt++;
                    colsn = true;
                }
                if(colsn) st.push('S');
            }
        }
        return cnt;
    }
};
int main(){
    int t;
    cin>>t;
    vector<int> ans;
    Solution s=Solution();
    while(t--){
        string str;
        cin>>str;
        ans.push_back(s.countCollisions(str));
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
}
