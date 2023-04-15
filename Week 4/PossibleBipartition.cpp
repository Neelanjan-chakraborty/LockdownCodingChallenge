/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/
class Solution {
public:
bool dfs(vector<vector<int>> &adj, vector<int> &color, int src, int c){
  if(color[src]!=0) 
    return (color[src]==c);
  color[src]=c;
  for(auto v:adj[src]){
    if(!dfs(adj,color,v,(c==1)?2:1)) 
        return false;
  }
  return true;
}
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
  vector<vector<int>> adj(N+1);
  for(auto x:dislikes){
    adj[x[0]].push_back(x[1]);
    adj[x[1]].push_back(x[0]);
  }
  vector<int> color(N+1,0);
  for(int i=1;i<=N;i++)
    if(!color[i] && !dfs(adj,color,i,1))
      return false;
  return true;
}
};
