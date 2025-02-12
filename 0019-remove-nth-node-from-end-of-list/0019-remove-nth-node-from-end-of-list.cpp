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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return nullptr;
        }

        ListNode* fast = head;


        int i = 0;

        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* slow = &dummy;

        while(fast != nullptr){
            if(i >= n){
                slow = slow->next;
            }
            i++;
            fast = fast->next;
        }

        if(slow == &dummy){
            return head->next;
        } else {
            if(slow->next == nullptr){
                return nullptr;
            }
            slow->next = slow->next->next;
        } 
        return head;

    }
};