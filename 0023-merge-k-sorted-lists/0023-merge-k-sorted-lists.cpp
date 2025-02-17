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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b){
            if(a == nullptr){
                return false;
            } else if (b == nullptr){
                return true;
            }
            return a->val > b -> val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        for(const auto & list : lists){
            ListNode* cur = list;
            while(cur != nullptr){
                pq.push(cur);
                cur = cur->next;
            }
        }

        if(pq.empty()){
            return nullptr;
        }

        ListNode* head = pq.top();
        pq.pop();
        ListNode* cur = head;
        while(!pq.empty()){
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;

    }

};