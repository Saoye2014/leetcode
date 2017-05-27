/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      stack<TreeNode*> res;
      vector<int> rtn;
      TreeNode* cur = root;
      res.push(cur);
      while(!res.empty()){
	cur = res.top();
	if(cur->left != NULL)
	  res.push(cur->left);
	else{
	  if(cur->right != NULL)
	    res.push(cur->right);
	  else{
	    rtn.push_back(cur->val);
	    res.pop();
	  }
	}
      }
      return rtn;
    }
};

int main(){
  Solution n;
  T



















