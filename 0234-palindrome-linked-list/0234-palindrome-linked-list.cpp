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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return true;
        }
        //get tail and length of the list
        ListNode* tail = head;
        int len = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            len++;
        }


        //get the middle element
        ListNode* cur = head;
        ListNode* prev = nullptr;
        for(int i = 0; i < len / 2; i++){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode * left = prev;
        if(len % 2 == 1){
            cur = cur->next;
        }
        ListNode * right = cur;


        while(left != nullptr && right != nullptr){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;








    }
};