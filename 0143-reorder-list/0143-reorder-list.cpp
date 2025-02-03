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
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* mid = slow;

        while(fast != nullptr){
            mid = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
            }
        }

        ListNode* rCur = llReverse(mid);
        
        ListNode* cur = head;
        while(cur != nullptr && cur->next != nullptr && cur != rCur){
            ListNode* temp = cur->next;
            ListNode* temp2 = rCur->next;
            cur->next = rCur;
            rCur->next = temp;
            cur = temp;
            rCur = temp2;
        }

        if(cur != nullptr){
            cur->next = rCur;
        }
        if(rCur != nullptr){
            rCur->next = nullptr;
        }
        return;
    }
    ListNode* llReverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};