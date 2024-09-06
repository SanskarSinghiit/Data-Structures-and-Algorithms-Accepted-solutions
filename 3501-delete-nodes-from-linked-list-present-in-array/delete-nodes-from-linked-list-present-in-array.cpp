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

    bool find(int x, vector<int>& nums){
        return binary_search(nums.begin(), nums.end(), x);
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        while(find(head->val, nums) && head!=nullptr){ // means first x elements to be deleted; also head can't be nullptr as mentioned in question, but still
            head = head->next; 
        }
        if(head==nullptr){return nullptr;}
        // head now can never be a np,, as mentioned in question
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr != nullptr){
            if(find(curr->val, nums)){
                prev->next=curr->next;
            } else{
                prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};