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

            for(int ind = 0; ind < size; ind ++){

                auto [node, i] = q.front();
                q.pop();

                i -= idx;

                if(ind == 0){
                    first = i;
                }

                if(ind == size -1){
                    last = i;
                }

                if( node -> left){
                    q.push({node -> left, 2ll*i + 1});
                }  

                if(node -> right){
                    q.push({node -> right, 2ll*i + 2});
                }

            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};