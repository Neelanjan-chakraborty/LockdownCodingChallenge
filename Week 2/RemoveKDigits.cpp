/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
      string res="";
      if(k==0) return num;
      if(k>=num.size()) return "0";
      stack<char> st;
      st.push(num[0]);
      int count=0;
      for(int i=1;i<num.length();i++){
        if(st.empty()||count==k||st.top()<=num[i])
          st.push(num[i]);
        else{
          st.pop();
          count++;
          i--;
        }
      }
      while(!st.empty()){
        res=st.top()+res;
        st.pop();
      }
      res=res.substr(0,res.length()-(k-count));
      int ind=0;
      while(ind<res.length()&&res[ind]=='0') ind++;
      res=res.substr(ind);
      if(res=="")
        res="0";
      return res;
    }
};
