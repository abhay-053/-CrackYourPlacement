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
    bool isSymmetric(TreeNode* root) {
        return (root==NULL)|| isSym(root->left,root->right);
    }
    bool isSym(TreeNode* l,TreeNode* r)
    {
        if(l==NULL or r==NULL)
        {
            return l==r;
        }
        if(l->val!=r->val) return false;
        
        return isSym(l->left,r->right) && isSym(l->right,r->left);
    }
};