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

    int rec(TreeNode* node, bool& check){
        if(check==false){return -1;}
        if(node==nullptr){return 0;}
        int x = rec(node->left, check);
        int y = rec(node->right,check);
        if(abs(x-y)>1){check=false;}
        return max(x,y)+1;
    }


    bool isBalanced(TreeNode* root) {
        bool check = true;
        rec(root,check); // tells the height of root, but that not our interest;
        return check;
    }
};