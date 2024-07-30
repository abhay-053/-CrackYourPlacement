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
    int mini = INT_MAX;  
    int prevVal = -1;    
    void check(TreeNode* root) 
    {
        if (root != nullptr) 
        {
            check(root->left);
            if (prevVal != -1) 
            {
                mini = min(mini, abs(root->val - prevVal)); 
            }
            prevVal = root->val; 
            check(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        check(root);
        return mini;
    }
};