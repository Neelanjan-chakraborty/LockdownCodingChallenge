/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  
The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
*/
class Solution {
public:
vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
  vector<vector<int>> res;
  int i=0,j=0,n=a.size();
  while(i<a.size() && j<b.size()){
    int high=min(a[i][1],b[j][1]);
    int low=max(a[i][0],b[j][0]);
    if(low<=high)
      res.push_back({low,high});
    if(a[i][1]>b[j][1]) j++;
    else i++;
  }
  return res;
}
};
