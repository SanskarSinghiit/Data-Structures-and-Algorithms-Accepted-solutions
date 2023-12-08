// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void preorder(TreeNode* node, set<char>& s)
//     {
//         if(node==nullptr)
//         {
//             s.insert('('); s.insert(')');
//             return;
//         }
//         // str.push_back('(');
//         s.insert('(');
//         int value = node->val;
//         // vec.push_back(value);
//         // str.push_back(to_string(value));
//         string temp = to_string(value);
//         char c = temp[0];
//         s.insert(c);
//         preorder(node->left, s);
//         preorder(node->right,s);
//         s.insert(')');
//     }
//     string tree2str(TreeNode* root)
//     {
//         // vector<int> vec;
//         // string str;
//         set<char> s;  
//         preorder(root, s);
//         s.erase(s.begin()); // deletes first;
//         int p = s.size();
//         auto it = next(s.begin(), p-1);
//         s.erase(it); // deletes last;

//         int n = s.size();
//         for(int i = 0; i < n-1; i++)
//         {
//             if(str[i]=='(' && str[i+1]==')')
//             {
//                 char a = str[i-2];
//                 char b = str[i-1];
//                 if(b-'0'<=9 || (b==')' && a-'0'<=9))
//                 {
//                     auto it = next(s.begin(), i);
//                     s.erase(it);
//                     it = next(s.begin(), i+1);
//                     s.erase(it);
//                 }
//             }
//         }
//         string ans;
//         for(auto value : s)
//         {
//             ans.push_back(value);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string tree2str(TreeNode* root) {
        string str = "";
         check(root, str);
         return str;
    }
    void check(TreeNode* root, string &str) {
        if (root == NULL) {
            return;
        }
        str += to_string(root->val);
        if (root->left || root->right) {
            str += '(';
            check(root->left, str);
            str += ')';
        }
        if (root->right) {
            str += '(';
            check(root->right, str);
            str += ')';
        }
        
    }
    
};