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


// #define n1left node1->left

class Solution {
public:

    void f(int x){
        cout << "False"<<x<<'\n';
    }

    bool check(TreeNode* node1, TreeNode* node2){
        // if((node1==nullptr) != (node2==nullptr)){return false;}
        if(node1==nullptr && node2==nullptr){return true;}
        if(node1==nullptr && node2!=nullptr || 
           node1!=nullptr && node2==nullptr){return false;} // any one is nullptr cases handled;
        // now no one is nullptr
        // cout << "HI" << '\n';
        if(node1->val != node2->val){return false;}
        // cout << "HELO" << '\n';
        TreeNode* x1 = node1->left; TreeNode* x2 = node2->left;
        TreeNode* y1 = node1->right;TreeNode* y2 = node2->right;
        bool nx1 = (x1==nullptr); bool nx2 = (x2==nullptr);
        bool ny1 = (y1==nullptr); /*YE MADARCHOD SAALA*/ bool ny2 = (y2==nullptr); // YE MADARCHOD SALA 
        // if(!(((nx1==nx2) && (ny1==ny2)) || ((nx1==ny2) && (ny1==nx2)))){return false;} // tereko nullptr na hone pe kya dikkat hai
        if(nx1==true||nx2==true||ny1==true||ny2==true){
            // cout << "ATLEAST ONE IS NULLPTR" << '\n';
            // now atleast one is nullptr;
            bool a = ((nx1==nx2) && (ny1==ny2));
            bool b = ((nx1==ny2) && (ny1==nx2));
            // cout << "nx1 -> " << nx1 << '\n';
            // cout << "ny1 -> " << ny1 << '\n';
            // cout << "nx2 -> " << nx2 << '\n';
            // cout << "ny2 -> " << ny2 << '\n';
            // cout << "(nx1==nx2) -> " << (nx1==nx2) << '\n';
            // cout << "(ny1==ny2) -> " << (ny1==ny2) << '\n';
            // cout << "(nx1==ny2) -> " << (nx1==ny2) << '\n';
            // cout << "(ny1==nx2) -> " << (ny1==nx2) << '\n';

            // cout << "bools -> " << a << ' ' << b << '\n';
            if(!(((nx1==nx2) && (ny1==ny2)) || ((nx1==ny2) && (ny1==nx2)))){return false;}
        }
        // cout << "FINE" << '\n';
        int vx1 = nx1?-1:x1->val; int vx2 = nx2?-1:x2->val;
        int vy1 = ny1?-1:y1->val; int vy2 = ny2?-1:y2->val;
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        // cout << vx1 << ' ' << vy1 << ' ' << vx2 << ' ' << vy2 << '\n';
        if(!(((vx1==vx2) && (vy1==vy2)) || ((vx1==vy2) && (vy1==vx2)))){return false;}
        bool ans = false;
        if(((vx1==vx2) && (vy1==vy2))){
            // cout<<"casea"<<" for nodes "<<node1->val<<' '<<node2->val<<'\n';
            ans = check(x1, x2) && check(y1, y2);
        } else{
            // cout<<"caseb"<<" for nodes "<<node1->val<<' '<<node2->val<<'\n';
            ans = check(x1,y2) && check(y1, x2);
        } return ans;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // cout << "this is 1Left -> " << root1->left << '\n';
        // cout << "this is 1Right-> " << root1->right << '\n';
        // cout << "this is 2Left -> " << root2->left << '\n';
        // cout << "this is 2Right-> " << root2->right << '\n';
        return check(root1, root2);
    }
};