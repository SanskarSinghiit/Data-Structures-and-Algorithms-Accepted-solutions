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

    void traverse(TreeNode* node, int maxi, int mini, int& v){
        if(node==nullptr){
            return;
        }
        int x = max(abs(maxi - node->val), abs(mini - node->val));
        v = max(x, v);
        maxi = (node->val) > maxi ? node->val : maxi;
        mini = (node->val) < mini ? node->val : mini;
        traverse(node->left, maxi, mini, v);
        traverse(node->right,maxi, mini, v);
    }

    int maxAncestorDiff(TreeNode* root) {
        int v = -1;
        int maxi = root->val;
        int mini = root->val;
        traverse(root, maxi, mini, v);
        return v;
    }
};