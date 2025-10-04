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
    ListNode* insertionSortList(ListNode* head) {
        ListNode sen;
        ListNode* senPtr = &sen;

        ListNode* pickedEnd = senPtr;
        senPtr->next = head;
        while(pickedEnd->next != nullptr) {
            ListNode* picked = pickedEnd->next;
            ListNode* spotFinder = senPtr;

            while(spotFinder != picked) {
                if(spotFinder->next->val > picked->val){
                    break;
                }
                spotFinder = spotFinder->next;
            }

            if(spotFinder != picked) {
                pickedEnd->next = picked->next;
                picked->next = spotFinder->next;
                spotFinder->next = picked;

                
            } else {
                pickedEnd = picked;
            }
        }

        return senPtr->next;
    }
};