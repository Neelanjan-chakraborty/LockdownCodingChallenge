/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.
*/
class Solution {
public:
int maxUncrossedLines(vector<int>& a, vector<int>& b) {
  int n=a.size(),m=b.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //cout<<a[i]<<b[j]<<dp[i][j];
  }
  return dp[n][m];
}
};
