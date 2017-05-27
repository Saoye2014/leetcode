#include<iostream>
#include<list>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
  bool check(TreeNode *n1, TreeNode *n2){
    if(n1->left == NULL || n2->right == NULL)
      return n1 -> left == n2 ->right ? true :false;
    
    return n1->left->val == n2->right->val ? true : false;
  }

  bool isSymmetric(TreeNode* root) {
 /* version 2
    if(root == NULL)
      return true;

    return isSymmetricHelper(root->left, root->right);
 */
    list<TreeNode*> left;
    list<TreeNode*> right;

    TreeNode* cur_l, *cur_r;
    TreeNode*tmp;

    if(root == NULL)
      return true;
    if(root->left == NULL || root ->right == NULL)
       return root -> left == root ->right ? true :false;
    
    if(root->left->val != root->right -> val)
      return false;
    left.push_back(root->left);
    right.push_back(root->right);

    while(!left.empty()){
      cur_l = left.front();
      cur_r = right.front();
      left.pop_front();
      right.pop_front();

      if(check(cur_l, cur_r) && check(cur_r, cur_l)){
	if(cur_l->left != NULL){
	  left.push_back(cur_l->left);
	  right.push_back(cur_r->right);
	}
	if(cur_l->right != NULL){
	  left.push_back(cur_l->right);
	  right.push_back(cur_r->left);
	}
      }
      else
	return false;
    }
    return true;
  }
  //version 2
  bool isSymmetricHelper(TreeNode *n1, TreeNode *n2){
    if(n1==NULL && n2==NULL)
      return true;
    if(n1 == NULL || n2 == NULL)
      return false;
    if(n1->val != n2->val)
      return false;

    return isSymmetricHelper(n1->left, n2->right)&&isSymmetric(n1->right, n2->left);
  }
};


int main(){
  TreeNode * root = NULL;
  Solution ().isSymmetric(root);
}
  










