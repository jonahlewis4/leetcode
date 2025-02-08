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


        removeNullLists(lists);
        if(lists.size() == 0){
            return nullptr;
        }



        ListNode* head = min(lists);
        ListNode* cur = head;

        while(!lists.empty()){
            cur->next = min(lists);
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }


    void removeNullLists(vector<ListNode*>& lists){
        vector<ListNode*> ans;
        for(const auto & list : lists){
            if(list != nullptr){
                ans.push_back(list);
            }
        }
        lists = ans;
    }

    ListNode* min(vector<ListNode*>& lists){
        ListNode** min = &(lists[0]);
        for (auto & list : lists){
            if(list->val < (*min)->val){
                min = &list;
            }
        }
        ListNode* ans = *min;
        (*min) = (*min)->next;
        if((*min) == nullptr){
            swap(*min, lists[lists.size() - 1]);
            lists.pop_back();
        }
        return ans;
    }

};