/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/
class Solution {
public:
string frequencySort(string s) {
  unordered_map<char,int> mp;
  for(int i=0;i<s.length();i++)
    mp[s[i]]++;
  priority_queue<pair<int,string>> pq;
  for(auto x:mp)
    pq.push({x.second,string(x.second,x.first)});
  string res="";
  while(!pq.empty()){
    res+=(pq.top()).second;
    pq.pop();
  }
  return res;
}
};
