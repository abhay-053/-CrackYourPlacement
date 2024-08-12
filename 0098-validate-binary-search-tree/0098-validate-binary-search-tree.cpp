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
    bool check(TreeNode* root, long long mini , long long maxi)
    {
        if(!root)return true;

        if(root->val <= mini || root ->val >= maxi)
            return false;

        return check(root->left, mini, root->val ) && check(root->right, root->val , maxi);
    }
    bool isValidBST(TreeNode* root) 
    {
        return check(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};