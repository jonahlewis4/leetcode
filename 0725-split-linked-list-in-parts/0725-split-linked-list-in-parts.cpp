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
    static int size(ListNode* head) {
        int res = 0;
        while(head != nullptr) {
            head = head->next;
            res++;
        }
        return res;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = size(head);
        int sizeOfGroup = len / k;
        int numPlus1 = len % k;
        
        vector<ListNode*> res(k, nullptr);
        ListNode* cur = head;
        for(int j = 0; j < k; j++) {
            int loopLen = numPlus1 > 0 ? sizeOfGroup + 1 : sizeOfGroup;
            numPlus1--;
            
            ListNode* curHead = cur;
            ListNode* prev = nullptr;
            for(int i = 0; i < loopLen; i++) {
                prev = cur;
                cur = cur->next;
            }

            res[j] = curHead;
            
            if(prev) {
                prev->next = nullptr;
            }
        }

        return res;

    }
};