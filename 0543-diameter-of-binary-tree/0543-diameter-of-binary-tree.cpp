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
    int height(TreeNode* root,int *h1)
    {
        if(root==NULL)return 0;
            int l= height(root->left, h1);
            int r= height(root->right, h1);
            *h1= max(*h1, l+r);
            return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h1=0;
        height(root,&h1);
        return h1;
    }
};