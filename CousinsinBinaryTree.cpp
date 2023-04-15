/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool isCousins(TreeNode* root, int x, int y) {
  if(!root) return false;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    int size=q.size();
    bool num1=false,num2=false;
    while(size--){
      TreeNode* root=q.front();
      q.pop();
      if(root->val==x) num1=true;
      if(root->val==y) num2=true;
      if(root->left&&root->right){
        if(root->left->val==x&&root->right->val==y) return false;
        if(root->left->val==y&&root->right->val==x) return false;
      }
      if(root->left) q.push(root->left);
      if(root->right) q.push(root->right);
    }
    if(num1&&num2) return true;
  }
  return false;
}
};
