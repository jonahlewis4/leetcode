/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head;
        while(true) {
            slow = slow.next;
            fast = fast.next;
            if(fast == null) {
                return false;
            }
            fast = fast.next;

            if(fast == slow) {
                return true;
            }
            if(fast == null) {
                return false;
            }
        }
    }
}