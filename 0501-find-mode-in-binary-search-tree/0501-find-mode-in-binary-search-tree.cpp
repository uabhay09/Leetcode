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
      int prev = INT_MIN, count = 0, max_count = 0;
    vector<int> ans;

    void inorder (TreeNode*root){  
         if (!root) return;   // empty condition
           // do inorder to get all element in sorted now traverse tht

          inorder(root->left);  // go left first
        if (root->val == prev)  // same number as before
            count++;            // increase streak
        else
            count = 1;          // new number, reset streak
             if (count > max_count) {        // new winner found
             max_count = count;          // update max
             ans = {root->val};       // clear old, add new
        } else if (count == max_count) { // tie found
            ans.push_back(root->val); // just add
        }
        prev = root->val;       // update prev for next node
        inorder(root->right);   // go right
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);  
        return ans;  
    }
};