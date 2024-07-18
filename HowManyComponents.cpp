/*You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array of m edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Print the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void get(int s,vector<vector<int>> &g,int &y,vector<bool> &v){
        if(v[s])return;
        v[s] = true;
        y++;
        for(auto &i: g[s]){
            get(i,g,y,v);
        }
    }
    void solve(int s,vector<vector<int>> &g,int &x,int &y,vector<bool> &v){
        if(v[s])return;
        v[s] = true;
        for(auto &i: g[s]){
            if(g[i].size() != y)x = 0;
            solve(i,g,x,y,v);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<bool> v1(n,false),v2(n,false);
        for(auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        int y = 0,x=0,ans=0;
        for(int i = 0; i < n; i++){
            if(!v1[i]){
                y = -1;
                get(i,g,y,v1);
                x = 1;
                solve(i,g,x,y,v2);
                ans += x;
            }
        }
        return ans;
    }
};
int main(){
    Solution s=Solution();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> aux;
    for(int i=0;i<n;i++){
        vector<int> abc;
        int temp;
        cin>>temp;
        abc.push_back(temp);
        cin>>temp;
        abc.push_back(temp);
        aux.push_back(abc);
    }
    cout<<s.countCompleteComponents(m,aux);

}