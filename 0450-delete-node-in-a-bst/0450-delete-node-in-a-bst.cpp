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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;  //empty BST

          if (key < root->val) {
            root->left = deleteNode(root->left, key);  // go left
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key); // go right
        }
        else {
            // Step 2: found the node — handle 3 cases
            // Case 1 & 2: no left child → right child takes over
            if (!root->left) return root->right;

            // Case 2: no right child → left child takes over
            if (!root->right) return root->left;

             // Case 3: two children
            // leftmost node in right subtree
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }

            // Copy successor's value into current node
            root->val = successor->val;

            // Delete the successor from right subtree
            root->right = deleteNode(root->right, successor->val);
        }

        return root;






    }
};