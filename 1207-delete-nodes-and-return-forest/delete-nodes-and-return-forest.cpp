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

// #define pb push_back;

void rec(TreeNode* node, queue<TreeNode*>& q,  unordered_set<int>& usd, map<TreeNode*, pair<TreeNode*, char>>& mp){
    if(node==nullptr){
        return;
    }
    // cout << "successfully inside rec " << '\n';
    if(usd.find(node->val) != usd.end()){
        // cout << "node " << node->val << " found inside usd " << '\n';
        if(node->left != nullptr){
            // cout << "pushing " << node->left->val << '\n';
            q.push(node->left);
        }
        if(node->right != nullptr){
            // cout << "pushng " << node->right->val << '\n';
            q.push(node->right);
        }
        // destruction of the node;
        node->left = nullptr; node->right = nullptr;
        TreeNode* parent = mp[node].first;
        char c = mp[node].second;
        if(parent!=nullptr){
            if(c=='L'){
                parent->left = nullptr;
            } else{
                parent->right = nullptr;
            }
        }
    }
        rec(node->left, q, usd, mp);
        rec(node->right, q, usd, mp);
}

void fillMap(map<TreeNode*, pair<TreeNode*, char>>& mp, TreeNode* node){
    if(node==nullptr){
        return;
    }
    if(node->left != nullptr){
        mp.insert({node->left, {node, 'L'}});
    }
    if(node->right != nullptr){
        mp.insert({node->right, {node, 'R'}});
    }
    fillMap(mp, node->left);
    fillMap(mp, node->right);
}

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> roots;
        queue<TreeNode*> q;
        unordered_set<int> usd;
        map<TreeNode*, pair<TreeNode*, char>> mp;  // (node, {parent, L or R child});
        fillMap(mp, root);
        // cout << "printingg the map => " << '\n';
        // for(auto x : mp){
        //     cout << x.first->val << " " << x.second.first->val << " " << x.second.second << '\n';
        // }
        for(auto val : to_delete){
            usd.insert(val);
        }
        // cout << "this is usd => " << " ";
        // for(auto val : usd){cout << val << ' ';} cout << '\n';
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            if(usd.find(node->val) == usd.end()){
                roots.push_back(node);
            }
            q.pop();
            // cout << "calling rec for " << node->val << '\n';
            rec(node, q, usd, mp);
            // cout << "after calling recursion this is q size => " << q.size() << '\n';
        }
        return roots;
    }
};