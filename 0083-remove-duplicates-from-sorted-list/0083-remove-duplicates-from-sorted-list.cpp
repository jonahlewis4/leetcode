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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* cur = head;
        ListNode* lookAhead = head->next;

        while(lookAhead != nullptr){
            if(lookAhead->val != cur->val){
                cur->next = lookAhead;
                cur = lookAhead;
            }
            lookAhead = lookAhead->next;
        }
        cur->next = nullptr;
        return head;
    }
};