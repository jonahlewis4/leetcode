/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode prev = head;
        int i = 0;
        int min = Integer.MAX_VALUE;
        int max = -1;
        int firstPoint = -1;
        int lastPoint = -1;
        for(ListNode cur = head.next; cur.next != null; i++, cur = cur.next) {
            boolean critPoint = (
                prev.val < cur.val && cur.next.val < cur.val
            ) || (
                prev.val > cur.val && cur.next.val > cur.val
            );
            
            if(critPoint) {
                if(firstPoint == -1) {
                    firstPoint = i;
                } else {
                    max = i - firstPoint;
                }

                if(lastPoint != -1) {
                    min = Math.min(min, i - lastPoint);
                }
                lastPoint = i;
            }

            prev = cur;
        }

        if(max == -1) {
            return new int[]{-1, -1};
        }

        return new int[]{min, max};
    }
}