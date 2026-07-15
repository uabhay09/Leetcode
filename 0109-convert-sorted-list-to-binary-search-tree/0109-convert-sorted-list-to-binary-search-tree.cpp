/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode*buildBST(vector<int>&Tree,int start,int end)
    {
        if(start>end) return NULL;

        int mid=start+(end-start)/2;
        TreeNode*root = new TreeNode(Tree[mid]);

        root->left = buildBST(Tree,start,mid-1);
        root->right = buildBST(Tree,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int>Tree;
        while(head)
        {
           Tree.push_back(head->val);
           head=head->next;
        }
         
        return buildBST(Tree,0,(int)Tree.size()-1);
    }
};