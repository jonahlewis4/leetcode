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
        ListNode* far = head;

        ListNode* notFar = new ListNode(-1);
        ListNode* negPos = notFar;
        notFar->next = head;
        int i = 0;
        while(far != nullptr){
            far = far->next;
            if(i >= n){
                notFar = notFar->next;
            }
            i++;
        }
        ListNode* to_delete = notFar->next;
        notFar->next = to_delete->next;
        if(notFar == negPos){
            head = head->next;
        }
        //delete to_delete;
        delete negPos;

        return head;
        

    }
};