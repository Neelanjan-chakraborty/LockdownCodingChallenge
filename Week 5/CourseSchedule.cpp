/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
*/
class Solution {
public:
bool dfs(vector<vector<int>> &adj,int s,vector<int> &vis){
  vis[s]=1;
  for(auto v:adj[s]){
    if(vis[v]==1) return false;
    if(vis[v]==0){
      if(!dfs(adj,v,vis))
        return false;
    }
  }
  vis[s]=2;
  cout<<s;
  return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> adj(numCourses);
  for(auto x:prerequisites)
    adj[x[0]].push_back(x[1]);
  stack<int> st;
  vector<int> vis(numCourses,0);
  for(int i=0;i<numCourses;i++)
    if(vis[i]==0)
    if(!dfs(adj,i,vis))
      return false;
  return true;
}
};
