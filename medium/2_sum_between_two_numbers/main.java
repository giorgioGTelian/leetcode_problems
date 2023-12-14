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
public final class Solution {
    public static final ListNode addTwoNumbers(
        ListNode l1, 
        ListNode l2
    ) {
        int left = 0;
        ListNode sentinel = new ListNode(0);
        ListNode tail = sentinel;

        while (!(l1 == null && l2 == null && left == 0)) {
            final int add1 = l1 != null ? l1.val : 0;
            final int add2 = l2 != null ? l2.val : 0;
            final int sum = add1 + add2 + left;
            left = sum / 10;
            final ListNode tempNode = new ListNode(sum % 10);
            tail.next = tempNode;
            tail = tempNode;

            if (l1 != null) {
                l1 = l1.next;
            }

            if (l2 != null) {
                l2 = l2.next;
            }

        }

        return sentinel.next;
    }
}
