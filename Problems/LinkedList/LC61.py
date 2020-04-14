#https://leetcode.com/problems/rotate-list/
"""
Find the length of the linked list and then reach upto that point 
that we want to rotate and then rotate from there
length finding is important as length of k can be larger then length itself
so we have to take modulus of it
"""
#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head==None:
            return head
        lt = 0
        tempHead = head
        while(tempHead!=None):
            lt+=1
            tempHead = tempHead.next
        k%=lt
        if(k==0):
            return head
        toReach = lt-k
        a = head
        b = head
        n = 0
        while(n<toReach):
            n+=1
            temp = b
            b = b.next
        temp.next = None
        toret = b
        while(b.next!=None):
            b = b.next
        b.next = a
        return toret