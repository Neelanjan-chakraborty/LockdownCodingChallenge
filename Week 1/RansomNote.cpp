/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26]={0};
        for(char x:magazine)
            mag[x-'a']++;
        for(char x:ransomNote){
            mag[x-'a']--;
            if(mag[x-'a']<0) 
                return false;
        }
        return true;
            
    }
};
