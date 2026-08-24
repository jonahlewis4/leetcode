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
            if(slow == null) {
                return false;
            }
            if(fast == null) {
                fast = head;
            } else {
                fast = fast.next;
            }
            if(fast == null) {
                fast = head;
            } else {
                fast = fast.next;
            }
            if(slow == fast) {
                return true;
            }
        }
    }
}