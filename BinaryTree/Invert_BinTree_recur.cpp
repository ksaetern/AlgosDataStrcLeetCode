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
            //Run the cursion until you hit the base
            //Post Order Traversal
            invertTree(root->left);
            invertTree(root->right);

            //then do the swap
            TreeNode *tmp;
            tmp = root->left;
            root->left = root->right;
            root->right = tmp;            
        }
        return root;
    }
};