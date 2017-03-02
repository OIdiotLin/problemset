/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        ListNode pre = head;
        ListNode cur = head;
        ListNode tail = head;
        int length = 0;
        while (cur != null) {
        	length++;
        	tail = cur;
        	cur = cur.next;
        }
        k = k % length;
        if (k == 0) {
        	return head;
        }
        int cutPos = length - k;
        while (cutPos > 0) {
        	pre = cur;
        	cur = cur.next;
        	cutPos--;
        }
        tail.next = head;
        pre.next = null;
        return cur;
    }
}