/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void f(Node* node, vector<int>& ans){
        if(node==nullptr){
            return;
        }
        // vector<int> children = node->
        for(auto child : node->children){
            f(child, ans);
        }
        ans.push_back(node->val);
        return;
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};