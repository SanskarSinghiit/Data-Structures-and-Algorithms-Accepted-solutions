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

    void fillValues(vector<int>& values, TreeNode*& root){
        if(root==nullptr){
            return;
        }
        fillValues(values, root->left);
        values.push_back(root->val);
        fillValues(values, root->right);
        return;
    }

    void create(vector<int>& values, TreeNode*& node, int l, int r){
        if(l > r){return;}
        if(l<0 || r<0 || l>= values.size() || r >= values.size()){return;}
        int mid = l + (r-l)/2;
        node = new TreeNode(values[mid]);
        create(values, node->left, l, mid-1);
        create(values, node->right, mid+1, r);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        fillValues(values, root);
        TreeNode* newRoot = nullptr;
        int n = values.size();
        int l = 0;
        int r = n-1;
        create(values, newRoot, l, r);
        return newRoot;
    }
};