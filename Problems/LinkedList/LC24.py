#https://leetcode.com/problems/swap-nodes-in-pairs/submissions/
"""
Main task here is to avoid replacing the values themselves 
so we replace the nodes and keeping a copy of the end node to 
with us every time and to attach to the newly reverse nodes
"""
#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head==None:
            return head
        sp=head
        fp=head.next
        flag = True
        keep = head
        while(sp and fp):
            sp.next = fp.next
            fp.next = sp
            if flag==False:
                keep.next = fp
            if flag:
                toRet = fp
                flag = False
            keep = sp
            sp=sp.next
            if sp!= None:
                fp=sp.next
            else:
                fp=None
        return toRet
        