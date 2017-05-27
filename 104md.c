#include<stdio>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
  if(root == NULL)
    return 0;
  int l = maxDepth(root->left);
  int r = maxDepth(root->right);
  int max = 1 + (r > l ? r : l);
 
  return max;
    
}
