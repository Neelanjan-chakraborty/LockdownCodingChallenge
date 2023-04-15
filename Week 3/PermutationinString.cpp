/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {      
      if(s1.length()>s2.length()) return false;
      int count[26]={0};
      int res=0;
      for(int i=0;i<s1.length();i++){
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
      }
      for(int i=0;i<26;i++)
        if(count[i]>0) 
          res+=count[i];
      if(res==0) return true;
      for(int i=s1.length();i<s2.length();i++){
        if(++count[s2[i-s1.length()]-'a']>0) res++;
        if(count[s2[i]-'a']-- > 0) res--;
        if(res==0) return true;
      }
      return false;
    }
};
