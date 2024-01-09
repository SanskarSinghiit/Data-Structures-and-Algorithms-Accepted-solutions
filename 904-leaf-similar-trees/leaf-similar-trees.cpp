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

    bool isLeaf(TreeNode* vertex){
        if(vertex->left==nullptr && vertex->right==nullptr){
            return true;
        }
        return false;
    }

    void leafTraversal(vector<int>& vec, TreeNode* vertex){
        if(vertex==nullptr){
            return;
        }
        leafTraversal(vec, vertex->left);
        if(isLeaf(vertex)){
            vec.push_back(vertex->val);
            // cout << ans.back() << ' ';
        }
        leafTraversal(vec, vertex->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> v1, v2;
        leafTraversal(v1, root1);
        leafTraversal(v2, root2);
        return v1==v2;
    }
};