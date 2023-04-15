/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
*/
class Solution {
public:
bool checkStraightLine(vector<vector<int>>& coordinates) {
  if(coordinates.size()<=2) return true;
  int x0,x1,y0,y1;
  x0=coordinates[0][0];
  y0=coordinates[0][1];
  x1=coordinates[1][0];
  y1=coordinates[1][1];
  int dx=x1-x0,dy=y1-y0;
  for(int i=3;i<coordinates.size();i++){
    if(dx*(coordinates[i][1]-y1)!=dy*(coordinates[i][0]-x1))
      return false;
  }
  return true;
}
};
