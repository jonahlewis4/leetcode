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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;

        while(curA != nullptr || curB != nullptr){
            if(curA == nullptr){
                curA = headB;
            }
            if(curB == nullptr){
                curB = headA;
            }
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};