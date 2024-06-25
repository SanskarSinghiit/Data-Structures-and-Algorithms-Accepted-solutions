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

    void remakeBST(TreeNode*& node, map<int, int>& mp){
        if(node==nullptr){
            return;
        }
        node->val = mp[node->val];
        remakeBST(node->left, mp);
        remakeBST(node->right, mp);
    }

    void fillVec(vector<int>& values, TreeNode* node){
        if(node==nullptr){
            return;
        }
        values.push_back(node->val);
        fillVec(values, node->left);
        fillVec(values, node->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        vector<int> values;
        TreeNode* node = root;
        fillVec(values, node);
        map<int, int> mp;
        int n = values.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += values[i];
        }
        for(int i = 0; i < n; i++){
            mp[values[i]] = -1;
        }
        sort(values.begin(), values.end());
        int tillSum = 0;
        for(int i = 0; i < n; i++){
            tillSum += values[i];
            mp[values[i]] = values[i] + (totalSum - tillSum);
        }
        remakeBST(root, mp);
        return root;
    }
};