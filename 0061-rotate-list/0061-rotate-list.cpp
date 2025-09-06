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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) {
            return head;
        }
        if(head == nullptr) {
            return head;
        }
        if(head->next == nullptr) {
            return head;
        }
        ListNode* cur = head;
        ListNode* ahead = cur;
        ListNode* prev = nullptr;
        for(int i = 0; i < k + 1; i++) {
            if(ahead == nullptr) {
                return rotateRight(head, k % i); 
            }
            prev = ahead;
            ahead = ahead->next;
        }
        while(ahead != nullptr) {
            prev = ahead;
            ahead = ahead->next;
            cur = cur->next;
        }
        ListNode* res = cur->next;
        cur->next = nullptr;
        prev->next = head;
        return res;

    }
};