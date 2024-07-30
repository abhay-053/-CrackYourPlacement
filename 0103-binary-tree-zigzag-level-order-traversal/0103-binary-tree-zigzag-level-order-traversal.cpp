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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > vv;
        TreeNode* ptr;
        if(root==NULL)
            return {};
        q.push(root);
        int i=0;
        while(!q.empty())
        {
            vector<int> v;
            int t=q.size();
            while(t--)
            {
                ptr= q.front();
                q.pop();
                v.push_back(ptr->val);
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
            }
            if(i%2==1)
            {
                reverse(v.begin(),v.end());
            }
            vv.push_back(v);
            i++;
        }
        return vv;
    }
};