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
      TreeNode* arraytoBST(vector<int>&arr,int start, int end){
        if(start>end) return NULL;   // all value traversed go back
        
        //divide array from middle make it root node
        int mid = start +(end - start)/2;
        TreeNode*root = new TreeNode(arr[mid]);

        //similarly create left and right subtree
        root->left =  arraytoBST(arr,start,mid-1);
        root->right =  arraytoBST(arr,mid+1,end);

        return root;
      }


   
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return arraytoBST(nums,0,nums.size()-1);

    }
};