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
    

    int amountOfTime(TreeNode* root, int start) {
      int timer = 0;
      Burn(root,timer,start);
      return timer;
    }
     int Burn(TreeNode*root,int &timer, int start){
      if(!root) return 0;

        if(root->val==start) {
            int h=Height(root)-1;
            timer=max(timer,h);
            return -1;
        }
        int left =  Burn(root->left,timer,start) ;
        int right = Burn(root->right,timer,start) ;

        if(left<0)
        {
            timer=max(timer,abs(left)+Height(root->right));
            return left-1;
        }
          if(right<0)
        {
            timer=max(timer,abs(right)+Height(root->left));
            return right-1;
        }
        return 1+max(left,right);    
     }

     int Height(TreeNode*root)
     {
        if(!root) return 0;
        return 1+max(Height(root->left),Height(root->right));
     }
};