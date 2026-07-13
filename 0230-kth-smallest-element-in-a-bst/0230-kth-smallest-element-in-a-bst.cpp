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
      void ksum(TreeNode*root,int &ans,int &k){

      if(!root) return;
      //inorder traversal to get element min as we need min sum
     ksum(root->left,ans=0,k);
     k--;
     if(k>=0)
     ans=root->val;
     if(k<=0)
     return;
     ksum(root->right,ans,k); 
      }


    int kthSmallest(TreeNode* root, int k) {
        int ans = 0; 
          ksum(root,ans,k); 
         return ans;
    }
};