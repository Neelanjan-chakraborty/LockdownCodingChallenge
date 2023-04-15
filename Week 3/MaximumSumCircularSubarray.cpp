/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
      int curmax=0,curmin=0,total=0;
      int maxsum=INT_MIN,minsum=INT_MAX;
      for(int i=0;i<arr.size();i++){
        curmax=max(curmax+arr[i],arr[i]);
        maxsum=max(maxsum,curmax);
        curmin=min(curmin+arr[i],arr[i]);
        minsum=min(minsum,curmin);
        total+=arr[i];
      }
      return(maxsum>0)?max(total-minsum,maxsum):maxsum;
    }
};
