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
        ListNode* right = head;
        ListNode* left = head;
        int rC = 1;

        bool first = true;
        ListNode* prev = nullptr;
        ListNode* connection = nullptr;
        while(right != nullptr){
            if(rC % k == 0){
                ListNode* next = right->next;
                right = next;

                ListNode* firstLeft = left;

                prev = nullptr;
                for(int i = 0; i < k; i++){
                    ListNode* temp = left->next;
                    left->next = prev;
                    prev = left;
                    left = temp;
                }
                
                if(first){
                    head = prev;
                    first = false;
                } else {
                    connection->next = prev;
                }
                connection = firstLeft;
                
            } else {
                prev = right;
                right = right->next;
            }
            rC++;
        }
        if(connection) {
            connection->next = left;
        }
        return head;
    }
};