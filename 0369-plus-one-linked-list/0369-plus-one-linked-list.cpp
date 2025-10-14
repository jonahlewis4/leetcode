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
    ListNode* reverse(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* rbegin = reverse(head);
        rbegin->val++;
        ListNode* cur = rbegin;
        while(cur->val == 10){
            cur->val = 0;
            if(cur->next == nullptr) {
                cur->next = new ListNode(1);
            } else {
                cur->next->val++; 
            }
            cur = cur->next;
        }
        return reverse(rbegin);
    }
};