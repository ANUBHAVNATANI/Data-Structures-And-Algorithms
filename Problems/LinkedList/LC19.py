#https://leetcode.com/problems/remove-nth-node-from-end-of-list/
"""
Basic idea is to take 2 pointers move one to the if the node is 
at the n from the end so it will be len(list)-n from the start
so move the first pointer by n and when it reaches n we start the other
pointer moving once the first one finishes we get the nth at its place
and then just remove the node from there
"""

#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        temp1 = head
        temp2 = head
        count = 0
        while(temp1.next!=None):
            count+=1
            temp1 = temp1.next
            if(count>n):
                temp2 = temp2.next
        if count==n-1:
            return head.next
        else:
            temp2.next = temp2.next.next
            return head