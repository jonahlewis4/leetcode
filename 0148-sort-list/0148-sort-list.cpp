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
private:
    int dist(ListNode* begin, ListNode* end) const {
        int count = 0;
        while(begin != end){
            begin = begin->next;
            count++;
        }
        return count;
    }
    ListNode* add(ListNode* begin, int amt) const {
        while(amt > 0 && begin != nullptr){
            begin = begin->next;
            amt--;
        }
        return begin;
    }
    

    ListNode* merge(ListNode* l, ListNode* lEnd, ListNode* r, ListNode* rEnd) const {
        ListNode start = ListNode(INT_MIN);
        ListNode *merged = &start;

        while(l != lEnd || r != rEnd) {
            if(l == lEnd){
                merged->next = r;
                r = r->next;
                merged = merged->next;
            } else if(r == rEnd) {
                merged->next = l;
                l = l->next;
                merged = merged->next;
            } else if (l->val < r->val) {
                merged->next = l;
                l = l->next;
                merged = merged->next;

            } else {
                merged->next = r;
                r = r->next;
                merged = merged->next;
            }
        }

        merged->next = r;
        return start.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode* back = head;
        while(back -> next != nullptr){
            back = back->next;
        }

        int n = dist(head, back) + 1;

        for(int size = 1; size < n; size *= 2){
            ListNode* sub1 = head;
            ListNode* sub2 = add(head, size);

            ListNode* sub1End = add(head, size);
            ListNode* sub2End = add(sub2, size);
            ListNode* prev = nullptr;
            while(sub1 != nullptr) {
                ListNode* base = merge(sub1, sub1End, sub2, sub2End);
                if(sub1 == head) {
                    head = base;
                } else {
                    prev->next = base;
                }
                prev = add(base, size * 2 - 1);
                sub1 = add(base, size * 2);
                sub1End = add(sub1, size);
                sub2 = sub1End;
                sub2End = add(sub2, size);
            }

        }

        return head;
    }
};