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
    TreeNode* solve(TreeNode* root1 )
    {
        if(root1==NULL )
        {
            return NULL ;
        }
        swap(root1->left, root1->right);
        solve(root1->left );
        solve(root1->right);
        return root1;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root!=NULL)
            solve(root);
        return root;
    }
};