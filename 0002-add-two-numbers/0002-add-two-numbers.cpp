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
        ListNode* cur = nullptr;
        int carry = 0;
        ListNode* head;
        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr && l2 != nullptr){
                int sum = l1->val + l2->val + carry;
                goofyAhAppend(head, cur, sum, carry);
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != nullptr){
                int sum = l1->val + carry;
                goofyAhAppend(head, cur, sum, carry);
                l1 = l1->next;
            } else {
                int sum = l2->val + carry;
                goofyAhAppend(head, cur, sum, carry);
                l2 = l2->next;
            }
        }

        if(carry > 0){
            goofyAhAppend(head, cur, 1, carry);
        }
        return head;


    }

    void goofyAhAppend(ListNode* &head, ListNode* &cur, int sum, int &carry){
        int sumRem = sum % 10;
        carry = sum / 10;
        if(cur == nullptr){
            cur = new ListNode(sumRem);
            head = cur;
        } else {
            cur -> next = new ListNode(sumRem);
            cur = cur->next;
        }
    }

    int listLength (ListNode* head){
        ListNode* cur = head;
        int len = 0;
        while(cur != nullptr){
            cur = cur->next;
        }
        return len;
    }

};