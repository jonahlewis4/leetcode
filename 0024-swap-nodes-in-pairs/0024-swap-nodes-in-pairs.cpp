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
    ListNode* swapPairs(ListNode* head) {
        ListNode* fakeHead = new ListNode(-1);
        fakeHead->next = head;

        ListNode* connection = fakeHead;
        while(connection != nullptr){
            ListNode* first = connection->next;
            if(first == nullptr){
                break;
            }
            ListNode* second = first->next;
            if(second == nullptr){
                break;
            } 

            ListNode* third = second->next;

            second->next = first;
            first->next = third;
            connection->next = second;
            connection = first;
        }  
        ListNode* res = fakeHead->next;
        delete fakeHead;
        return res;
    }
};