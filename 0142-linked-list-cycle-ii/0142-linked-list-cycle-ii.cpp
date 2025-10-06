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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(true) {
            if(fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
            if(fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
            slow = slow->next;

            if(fast == slow) {
                break;
            }
        }

        ListNode* slow2 = head;
        while(slow2 != slow) {
            slow2 = slow2->next;
            slow = slow->next;
        }
        return slow;
    }
};