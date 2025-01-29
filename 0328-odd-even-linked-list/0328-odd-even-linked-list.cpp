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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }
        
        ListNode* firstEven = head->next;

        ListNode* cur = head;
        int i = 1;
        ListNode* lastOdd = head;
        while(true){
            if(i % 2 != 0){
                lastOdd = cur;
            }
            i++;
            ListNode* temp = cur->next;
            if(temp == nullptr){
                break;
            }
            cur->next = temp->next;
            cur = temp;
        }

        lastOdd->next = firstEven;
        
        return head;
    }
};