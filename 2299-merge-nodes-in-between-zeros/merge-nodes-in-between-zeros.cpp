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
    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* parent = head;
        ListNode* node = head;
        ListNode* newRoot = nullptr;
        int sum = 0;
        vector<int> vec;
        while(node != nullptr){
            if(node->val == 0){
                if(sum != 0){
                    vec.push_back(sum);
                }
                sum = 0;
            } else{
                sum += node->val;
            }
            node = node->next;
        }
        // cout <<  "printing vec => " << '\n';
        // for(auto val : vec){
        //     cout << val << ' ';
        // } cout << '\n';
        if(vec.size() == 0){
            return nullptr;
        }
        newRoot = new ListNode(vec[0]);
        int n = vec.size();
        ListNode* tracker = newRoot;
        for(int i = 1; i < n; i++){
            // cout << "now for => " << vec[i] << '\n';
            tracker->next = new ListNode(vec[i]);
            tracker = tracker->next;
        }
        return newRoot;
    }
};