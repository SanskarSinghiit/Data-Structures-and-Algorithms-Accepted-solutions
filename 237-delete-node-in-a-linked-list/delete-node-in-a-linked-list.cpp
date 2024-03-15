/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {  // node is passed by value here, fuggg so if I edited node, 
        ListNode* three = node->next;
        node->val = three->val;
        ListNode* four = three->next;
        node->next=four;
        three->next=nullptr;
    }
};