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
     TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        return buildTree(pre, 0, pre.size()-1, ino, 0, ino.size()-1); 
     }
    TreeNode*buildTree(vector<int>& pre, int ps, int pe,
                        vector<int>& ino , int is,int ie) {
        
         // step 1  edge case 
         if(ps>pe) return NULL; 
         //step 2 pick root
         int rootVal = pre[ps];
         TreeNode*root = new TreeNode(rootVal);
         // step 3 find root in inorder
         int mid = is;
         while (ino[mid] != rootVal)
          mid++;
         // step 4 calculate left subtree , no need to go for right as only right remaining
         int leftSize = mid - is;
         //step 5 recurse left
        root->left =  buildTree(pre, ps+1,ps+leftSize, ino, is, mid-1);
        //step 6 recurse right 
        root->right =  buildTree(pre, ps+leftSize+1, pe, ino, mid+1, ie);

        return root;



    }
};