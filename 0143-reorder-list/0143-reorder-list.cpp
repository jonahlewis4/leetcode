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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next;
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr){
                continue;
            }
            fast = fast->next;
        }

        ListNode* prev = nullptr;
        ListNode* rev = slow;
        while(rev != nullptr){
            ListNode* temp = rev->next;
            rev->next = prev;
            prev = rev;
            rev = temp;
        }
        rev = prev;
        ListNode* cur = head;
        while(cur != nullptr && rev != nullptr){
            ListNode* curNext = cur->next;
            ListNode* revNext = rev->next;
            cur->next = rev;
            if(curNext == slow){
                
            } else {
                rev->next = curNext;
            }
            rev = revNext;
            cur = curNext;
        }
    }
};