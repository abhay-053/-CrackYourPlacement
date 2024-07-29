/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    void inorder(TreeNode* root)
    {
        if(root!=NULL)
        {
            if(root->left != NULL)
            {
                mp[root->left]=root;
            }
            inorder(root->left);
            if(root->right!=NULL)
            {
                mp[root->right]=root;
            }
            inorder(root->right);
        }
    }
    void bfs(TreeNode* target, int k , vector<int>& ans)
    {
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> vis;
        vis.insert(target->val);

        while(!q.empty())
        {
            int n= q.size();

            if(k==0)break;
            while(n--)
            {
                TreeNode* cur = q.front();
                q.pop();

                if(cur->left != NULL && !vis.count(cur->left->val))
                {
                    q.push(cur->left);
                    vis.insert(cur->left->val);
                }
                if(cur->right != NULL && !vis.count(cur->right->val))
                {
                    q.push(cur->right);
                    vis.insert(cur->right->val);
                }

                if(mp.count(cur) && !vis.count(mp[cur]->val)){
                    q.push(mp[cur]);
                    vis.insert(mp[cur]->val);
                }
            }
            k--;
        }
        while(!q.empty())
        {
            auto t= q.front();
            q.pop();
             ans.push_back(t->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector<int> ans;
       inorder(root);

        bfs(target, k,ans);
        return ans;
    }
};