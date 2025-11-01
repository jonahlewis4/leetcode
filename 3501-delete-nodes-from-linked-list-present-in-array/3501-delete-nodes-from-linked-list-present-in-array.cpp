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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode sen;
        ListNode* senPtr = &sen;
        senPtr->next = head;

        unordered_set<int> set;
        for(const int i : nums){
            set.insert(i);
        }

        ListNode* cur = senPtr;
        while(cur->next != nullptr){
            int nextVal = cur->next->val;
            if(set.contains(nextVal)){
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }


        return senPtr->next;
    }
};