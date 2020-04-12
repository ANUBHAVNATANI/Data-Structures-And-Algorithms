# https://leetcode.com/problems/subsets/
"""
Use backtracking to sought of make all the combination 
and when there are no combination possible just go up in that
tree of recursion like [1] -- > [1,2] -- > [1,2,3] just go up to [1]
by popping and similary no generating all the possibilities
"""
class Solution:
    def subsets(self, nums):
        ans = []
        if len(nums)==0:
            return [[]]
        def backTrack(ind=0,comb = []):
            if ind==len(nums):
                ans.append(comb[:])
                return
            else:
                ans.append(comb[:])
            for i in range(ind,len(nums)):
                comb.append(nums[i])
                backTrack(i+1,comb)
                comb.pop()
        backTrack()
        return ans