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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* returnValue = l1;
        ListNode* prev = nullptr;
        while(l1 != nullptr) {
            int sum = l1->val;
            if(l2 != nullptr) {
                sum += l2->val;
            }
            sum += carry;
            int digit = sum % 10;
            carry = sum / 10;
            l1->val = digit;

            prev = l1;
            l1 = l1->next;
            if(l2 != nullptr) {
                l2 = l2->next;
            }

            if(l1 == nullptr && l2 != nullptr) {
                prev->next = l2;
                l1 = l2;
                l2 = nullptr;
            }
        }
        if(carry > 0) {
            prev->next = new ListNode(1);
        }
        return returnValue;
    }
};