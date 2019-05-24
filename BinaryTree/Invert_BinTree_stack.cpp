/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
class Solution {
public:
    //O(n) non recursion
    //BFS traversal
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        
        //breathsearch
        while(!stk.empty())
        {
            TreeNode *curr = stk.top();
            stk.pop();
            
            //swap
            TreeNode *tmp;
            
            tmp = curr->right;
            curr->right = curr->left;
            curr->left = tmp;
            //if theres still more
            if(curr->right)
                stk.push(curr->right);
            if(curr->left)
                stk.push(curr->left);
        }
        return root;
    }
};