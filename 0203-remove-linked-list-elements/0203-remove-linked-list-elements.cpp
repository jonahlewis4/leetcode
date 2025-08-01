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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode sen = ListNode(-1);
        sen.next = head;
        ListNode* prev = &sen;
        while(cur != nullptr) {
            if(cur->val == val){
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
            
            cur = prev->next;
            
        }
        return sen.next;

    }
};