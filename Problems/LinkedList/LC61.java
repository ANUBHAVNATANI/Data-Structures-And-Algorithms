/*
#https://leetcode.com/problems/rotate-list/
"""
Find the length of the linked list and then reach upto that point 
that we want to rotate and then rotate from there
length finding is important as length of k can be larger then length itself
so we have to take modulus of it
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
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null) return head;
        if(head.next == null) return head;
        if(k==0) return head;
        int length=0;
        ListNode tempNode = head;
        //finding the length of the linked list
        while(tempNode!=null){
            tempNode = tempNode.next;
            length++;
        }
        int v;
        if((k>length && k%length==0) || k==length) return head;
        else if(k>length) v = length-(k%length);
        else v = length-k;
        // keeping at the three places in the linked list
        ListNode prev = null;
        ListNode curr = null;
        ListNode tempNode2 = head;
        ListNode currPrev = null;
        int count=0;
        while(tempNode2!=null){
            if(count==v){
                curr = tempNode2;
                currPrev = prev;
            }
            prev = tempNode2;
            tempNode2 = tempNode2.next;
            count++;
        }
        prev.next = head;
        currPrev.next = null;
        return curr;
    }
}