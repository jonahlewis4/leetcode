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
    public int length(ListNode l) {
        int res = 0;
        while(l != null) {
            res++;
            l = l.next;
        }
        return res;
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int length1 = length(l1);
        int length2 = length(l2);

        ListNode largerList;
        ListNode smallerList;
        if(length1 < length2) {
            largerList = l2;
            smallerList = l1;
        } else {
            largerList = l1;
            smallerList = l2;
        }

        ListNode sen = new ListNode();
        sen.next = largerList;
        ListNode carryTarget = sen;
        int lengthDiff = Math.abs(length1 - length2);
        for(int i = 0; i < Math.max(length1, length2); i++){
            if(i >= lengthDiff){
                largerList.val += smallerList.val;
            }

            boolean shouldCarry = largerList.val > 9;
            largerList.val %= 10;

            if(shouldCarry) {
                while(carryTarget != largerList) {
                    carryTarget.val++;
                    carryTarget.val %= 10;
                    carryTarget = carryTarget.next;
                }
                carryTarget = largerList;
            } else if (largerList.val != 9) {
                carryTarget = largerList;
            }

            largerList = largerList.next;
            if(i >= lengthDiff) {
                smallerList = smallerList.next;
            }
        }

        if(sen.val > 0) {
            return sen;
        } else {
            return sen.next;
        }
    }
}