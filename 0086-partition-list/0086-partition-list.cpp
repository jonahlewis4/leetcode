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
    ListNode* partition(ListNode* head, int x) {
        ListNode sen;
        ListNode* senCur = &sen;

        ListNode ogSen;
        ogSen.next = head;
        ListNode* prev = &ogSen;
        for(ListNode* cur = head; cur != nullptr; cur = cur->next) {
            if(cur->val < x) {
                senCur->next = cur;
                senCur = senCur->next;

                prev->next = cur->next;
            } else {
                prev = cur;
            }
        }  

        senCur->next = ogSen.next;

        return sen.next;
    }
};