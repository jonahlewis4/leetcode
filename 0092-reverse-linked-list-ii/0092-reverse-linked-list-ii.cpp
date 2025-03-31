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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        
        
        ListNode* dumHead = new ListNode(-1);

        ListNode* beforeReverse = dumHead;
        ListNode* afterReverse = nullptr;

        ListNode* leftNode = nullptr;
        ListNode* rightNode = nullptr;

       

        ListNode* cur = dumHead;
        dumHead->next = head;
        bool before = false;    

        ListNode* prev = nullptr;
        int i = 0;
        while(cur != nullptr){
            if(i == left){
                leftNode = cur;
            }
            if(!leftNode){
                beforeReverse = cur;
            }

            if(i == right){
                rightNode = cur;
            }

            if(rightNode && i != right && !afterReverse){
                afterReverse = cur;
            }
            if(leftNode && (!rightNode || i == right)){
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            } else {
                cur = cur -> next;
            }

            i++;

        }


        if(!leftNode || !rightNode){
            return head;
        }

        beforeReverse->next = rightNode;
        leftNode->next = afterReverse;
        ListNode* retVal = dumHead->next;
        delete dumHead;

        return retVal;
    }
};