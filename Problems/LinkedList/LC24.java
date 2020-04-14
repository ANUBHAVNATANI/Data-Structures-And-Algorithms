/*
#https://leetcode.com/problems/swap-nodes-in-pairs/submissions/
"""
Main task here is to avoid replacing the values themselves 
so we replace the nodes and keeping a copy of the end node to 
with us every time and to attach to the newly reverse nodes
"""
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        //we save head.next value in a
        ListNode a = head.next;
        //for next set of pairs we do this recursion and save it into the head.next
        head.next = swapPairs(head.next.next);
        //we set the a.next to the head
        a.next = head;
        return a;
    }
}