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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                // Reconnect the right subtree
                rightmost->right = curr->right;
                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next node in the right subtree
            curr = curr->right;
        }
    }
};