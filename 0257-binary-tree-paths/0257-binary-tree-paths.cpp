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
    vector<string> ans;
    void inorder(TreeNode* root, string str)
    {
        if(root!= NULL)
        {
            str = str + to_string(root->val);
            if(root->left == NULL && root->right == NULL)
            {
                ans.push_back(str);
            }
            str = str + '-' + '>';
            inorder(root->left, str);
            inorder(root->right, str);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str="";
        inorder(root,str);
        return ans;
    }
};