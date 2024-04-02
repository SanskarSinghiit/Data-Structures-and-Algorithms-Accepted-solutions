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

    void print(TreeNode* node){
        if(node==nullptr){
            return;
        }
        print(node->left);
        cout << node->val << ' ';
        print(node->right);
        return;
    }

    TreeNode* insertIntoBST(TreeNode* root_0, int val) {
        TreeNode* root = root_0;
        if(root == nullptr){
            TreeNode* root_0 = new TreeNode(val);
            return root_0;
        }
        while(root!=nullptr){
            int data = root->val;
            if(data < val){
                if(root->right == nullptr){
                    root->right = new TreeNode(val);
                    break;
                }
                root = root->right;
            } else if(data > val){
                if(root->left == nullptr){
                    root->left = new TreeNode(val);
                    break;
                }
                root = root->left;
            }
        }
        // root = new TreeNode(val);
        print(root_0);
        return root_0;
    }
};