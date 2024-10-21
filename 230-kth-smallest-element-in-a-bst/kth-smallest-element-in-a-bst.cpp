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

    void inorder(TreeNode* node, int k, int&x,int&count,bool&found){
        if(node==nullptr || found){return;}
        inorder(node->left, k, x, count, found);
        count++;
        if(count==k){x=node->val; found=true;}
        inorder(node->right,k,x, count, found);
    }


    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal of binary search tree gives sorted order;
        // find kth inorder root;
        int x = 0;
        int count = 0;
        bool found=false;
        inorder(root,k,x,count,found);
        return x;
    }
};




/*


 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:

    void fill(TreeNode* node, vector<int>& vec){
        if(node==nullptr){return;}
        vec.push_back(node->val);
        fill(node->left,vec);
        fill(node->right,vec);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        vector<int> vec;
        fill(root,vec);
        sort(vec.begin(),vec.end());
        return vec[k-1];
        // while(count<k){
        //     root=root->left;
        // }
    }
};







*/