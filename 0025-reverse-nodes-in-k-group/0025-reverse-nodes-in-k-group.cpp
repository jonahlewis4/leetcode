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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* l = head;
        ListNode* r = head;
        ListNode* link = nullptr;
        ListNode* newHead;
        while(r != nullptr){
            int i = 0;
            while (i < k) {
                if(r == nullptr){
                    break;
                }
                r = r->next;
                i++;
            }
            if(i < k){
                break;
            }

            ListNode* prev = nullptr;
            ListNode* oldLeft = l;

            for(int j = 0; j < k; j++){
                auto next = l -> next;
                l->next = prev;
                prev = l;
                l = next;
            }

            if(link){
                link->next = prev;
            } else {
                newHead = prev;
            }
            link = oldLeft;
        }
        if(link){
            link->next = l;
        }
        return newHead;

    }
};