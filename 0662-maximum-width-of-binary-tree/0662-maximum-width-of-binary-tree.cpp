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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 1;
        int first, last, size, idx;
        while(!q.empty()){
            size = q.size(); 
            idx = q.front().second;
            first = -1;
            last = -1;
            while(size --){
                auto [node, i] = q.front();
                q.pop();

                i -= idx;

                if(first == -1){
                    first = i;
                }

                if( node -> left){
                    q.push({node -> left, 2ll*i + 1});
                }  

                if(node -> right){
                    q.push({node -> right, 2ll*i + 2});
                }
                last = i;

            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};