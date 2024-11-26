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

    void rec(TreeNode* node, int& maxd, int score){
        if(node==nullptr){return;}
        if(node->left==nullptr && node->right==nullptr){ // means it is a leaf node
            maxd=max(maxd,score);
        }
        rec(node->left,maxd,score+1);
        rec(node->right,maxd,score+1);
    }

    int maxDepth(TreeNode* root) {
        // vector<>
        if(root==nullptr){return 0;}
        int maxd = -1;
        rec(root,maxd,1);
        return maxd;
    }
};