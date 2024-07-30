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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* cur;
        vector<vector<int> > vp;
        if(!root)return {};
        q.push(root);
        while(!q.empty())
        {
            vector<int> v;
            int t=q.size();
            while(t--)
            {
                cur=q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            vp.push_back(v);
        }
        return vp;
    }
};