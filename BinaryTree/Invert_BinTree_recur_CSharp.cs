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
    TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            //set up the recursion
            invertTree(root->right);
            invertTree(root->left);
            
            //get to base and swap
            TreeNode *tmp;
            tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        return root;
    }
};
