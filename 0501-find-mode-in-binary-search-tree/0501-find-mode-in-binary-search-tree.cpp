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

    void iterate(TreeNode* node, unordered_map<int, int>& um)
    {
        if(node==nullptr){return;}
        int value = node->val;
        if(um.find(value)==um.end())
        {
            um.insert({value, 1});
        }
        else
        {
            um[value]++;
        }
        iterate(node->left, um);
        iterate(node->right,um);
    }

    vector<int> findMode(TreeNode* root)
    {
        vector<int> ans;
        unordered_map<int, int> um;
        iterate(root, um);
        int maxcnt = 0;
        for(auto value : um)
        {
            int cnt = value.second;
            if(cnt>maxcnt){maxcnt=cnt;}
        }
        for(auto value : um)
        {
            if(value.second==maxcnt)
            {
                ans.push_back(value.first);
            }
        }
        return ans;
    }
};