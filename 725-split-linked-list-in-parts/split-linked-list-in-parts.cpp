/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int getSize(ListNode* node){
        if(node==nullptr){
            return 0;
        }
        return 1+getSize(node->next);
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = getSize(head);
        vector<ListNode*> vec;
        ListNode* node = head;
        // nodex->next = null
        if(n<=k){
            for(int i = 0; i < k; i++){
                if(node){
                    ListNode* nodex = node;
                    node=node->next;
                    nodex->next=nullptr;
                    vec.push_back(nodex);
                } else{
                    vec.push_back(nullptr);
                }
            }
            return vec;
        }
        int common_size = n/k;
        int special_groups = n%k;
        cout << "common -> " << common_size << ' ' << "special_groups -> " << special_groups << '\n';
        // out of k group, first n%k are special groups, so common_size+1
        while(k--){
            vec.push_back(node);
            ListNode* prev = nullptr;
            for(int i = 0; i < common_size + (special_groups>0); i++){
                prev=node;
                node=node->next;
            }
            prev->next=nullptr;
            special_groups--;
        }
        return vec;
    }
};