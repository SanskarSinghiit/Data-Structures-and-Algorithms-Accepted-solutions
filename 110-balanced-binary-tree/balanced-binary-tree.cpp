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

    int traverse(TreeNode* node, bool& x){
        if(node==nullptr){
            return 0;
        }
        if(x==false){
            return -1;
        }
        int L = traverse(node->left, x);
        int R = traverse(node->right, x);
        // return 1+max(L, R);
        if(x==false){
            return -1;
        }
        if(abs(L-R) > 1){
            x=false;
        }
        return 1+max(L, R);
    }

    bool isBalanced(TreeNode* root) {
        bool x = true;
        traverse(root, x);
        return x;
    }
};