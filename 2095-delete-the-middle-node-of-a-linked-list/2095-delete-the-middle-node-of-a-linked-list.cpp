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
    ListNode* deleteMiddle(ListNode* head) {
        // -1 0 
        // -1 0 1
        // -1 0 1 2 
        // -1 0 1 2 3 x x
        // -1 0 1 2 3 4 x x
        
        
        //-1 -1      
        //0 1
        //1 3
        //2 5
        //3 7
        ListNode sen;
        sen.next = head;
        if(!head->next){
            return nullptr;
        }

        ListNode* slow = &sen;
        ListNode* fast = slow->next->next;

        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
            }
            slow = slow->next;
        }

        ListNode* marked = slow->next;
        slow->next = marked->next;
        //delete marked;
        return sen.next;
        
    }
};