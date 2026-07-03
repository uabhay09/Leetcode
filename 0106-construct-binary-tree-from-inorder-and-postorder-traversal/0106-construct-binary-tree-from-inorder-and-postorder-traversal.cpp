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
           TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return  buildTree(inorder, postorder, 0, inorder.size()-1, postorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postEnd ) {
        if(inStart > inEnd) return NULL;

        int rootVal = postorder[postEnd];
         TreeNode*root = new TreeNode(rootVal);

         int pos = find(inorder.begin(),inorder.end(),rootVal)-inorder.begin();
         int leftSize = pos - inStart;

         root->left=buildTree(inorder,postorder,inStart,pos-1,postEnd -(inEnd-pos)-1);
         root->right=buildTree(inorder,postorder,pos+1,inEnd,postEnd-1);

         return root;













    }
};