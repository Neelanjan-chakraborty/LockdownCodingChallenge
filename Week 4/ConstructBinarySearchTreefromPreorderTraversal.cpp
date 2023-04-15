/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.
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
TreeNode* construct(vector<int> &preorder,int &i,int min,int max){
  if(i>=preorder.size())
    return NULL;
  TreeNode* root=NULL;
  if(preorder[i]>min && preorder[i]<max){
    root=new TreeNode(preorder[i++]);
    root->left=construct(preorder,i,min,root->val);
    root->right=construct(preorder,i,root->val,max);
  }
  return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
  if(preorder.size()==0) return NULL;
  int max=INT_MAX,min=INT_MIN,i=0;
  return construct(preorder,i,min,max);
}
};
