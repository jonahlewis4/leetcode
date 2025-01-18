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
        

        ListNode *cur1 = headA;
        ListNode *cur2 = headB;

        while(cur1 != nullptr || cur2 != nullptr){
            if(cur1 == nullptr){
                cur1 = headB;
            }
            if(cur2 == nullptr){
                cur2 = headA;
            }
            if(cur1 == cur2){
                return cur1;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return nullptr;
    }
};