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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode* head;
    int length(ListNode* head) {
        int len = 0;
        while(head != nullptr) {
            head = head->next;
            len++;
        }
        return len;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = length(head);
        this->head = head;
        return convert(0, len - 1);
    }
    TreeNode* convert(int l, int r) {
        if(l > r) {
            return nullptr;
        }
        
        int m = (l + r) / 2;
        TreeNode* left = convert(l, m - 1);
        TreeNode* cur = new TreeNode(head->val);

        cur->left = left;
        head = head->next;
        TreeNode* right = convert(m + 1, r);
        cur->right = right;
        return cur;
    }
};