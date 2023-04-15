/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/
class Solution {
public:
    int countZero(int count[]){
      int zero=0;
      for(int i=0;i<26;i++)
        if(count[i]==0) 
          zero++;
      return zero;
    }
    vector<int> findAnagrams(string s, string p) {
      vector<int> res;
      string s1=p,s2=s;
      if(s1.length()>s2.length()) return res;
      int count[26]={0};
      for(int i=0;i<s1.length();i++){
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
      }
      if(countZero(count)==26) 
        res.push_back(0);
      for(int i=s1.length();i<s2.length();i++){
        count[s2[i-s1.length()]-'a']++;
        count[s2[i]-'a']--;
        if(countZero(count)==26) 
          res.push_back(i-s1.length()+1);
      }
      return res;
    }
};
