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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if(!head || !head->next){return head;}
        prev = head;
        curr = curr->next;
        while(curr != nullptr){
            ListNode* mid = new ListNode(__gcd(prev->val, curr->val));
            prev->next = mid;
            mid->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};