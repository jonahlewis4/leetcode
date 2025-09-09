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
        ListNode* cur = head;
        ListNode sen;
        sen.next = head;
        ListNode* prev = &sen;
        while(cur != nullptr){
            ListNode* newPrevNext = cur;
            if(cur->next != nullptr && cur->next->val == cur->val) {
                while(cur->next != nullptr && cur->next->val == cur->val) {
                    cur = cur->next;
                    newPrevNext = cur->next;
                }

                prev->next = newPrevNext;
                cur = newPrevNext;
                continue;
            }
            prev = cur;
            cur = cur->next;

        }
        return sen.next;
    }
};