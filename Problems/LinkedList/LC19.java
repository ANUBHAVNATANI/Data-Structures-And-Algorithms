//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/*
"""
Basic idea is to take 2 pointers move one to the if the node is 
at the n from the end so it will be len(list)-n from the start
so move the first pointer by n and when it reaches n we start the other
pointer moving once the first one finishes we get the nth at its place
and then just remove the node from there
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode node1 = head;
        ListNode node2 = head;
        int count = 0;
        while(node1.next!=null){
            node1=node1.next;
            count++;
            if(count>n) node2=node2.next;
        }
        if(count==n-1) return head.next;
        else{
            node2.next = node2.next.next;
            return head;
        }
    }
}