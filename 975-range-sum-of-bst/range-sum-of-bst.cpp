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

    bool checker(int val, int low, int high){
        if(val>=low && val<=high){
            return 1;
        }
        return false;
    }

    void traverse(TreeNode* node, int low, int high, int& count){
        if(node==nullptr){return;}
        int value = node->val;
        if(checker(value, low, high)){
            count += value;
        }
        auto left = node->left;
        // if(left!=nullptr){
            traverse(left, low, high, count);
        // }
        auto right = node->right;
        // if(right!=nullptr){
            traverse(right, low, high, count);
        // }
    }

    int rangeSumBST(TreeNode* root, int low, int high)
    {
        int count = 0;
        traverse(root, low, high, count);
        return count;
    }
};