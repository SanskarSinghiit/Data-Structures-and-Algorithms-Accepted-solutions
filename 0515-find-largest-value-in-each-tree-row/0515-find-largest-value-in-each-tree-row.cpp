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

    void func(TreeNode* node, int cnt, vector<vector<int>>& vec)
    {
        if(node==nullptr){return;}
        vec[cnt].push_back(node->val);
        func(node->left, cnt+1, vec);
        func(node->right, cnt+1, vec);
    }    

    vector<int> largestValues(TreeNode* root)
    {
        int cnt = 0;
        vector<vector<int>> vec(1e4); // cnt0 wale first cnt1 wale 2nd .. and so on so we get all rows;
        func(root, cnt, vec);
        int n = 0;
        while(vec[n].size()!=0)
        {
            n++;
        }
        // cout << "PRINTING VEC : " << '\n';
        // for(int i = 0; i < n; i++)
        // {
        //     for(auto val : vec[i])
        //     {
        //         cout << val << ' ';
        //     }
        //     cout << '\n';
        // }
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            ans[i] = *max_element(vec[i].begin(), vec[i].end());
        }
        return ans;
    }
};