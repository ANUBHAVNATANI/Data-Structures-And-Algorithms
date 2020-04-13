#https://leetcode.com/problems/permutations-ii/
"""
This problem is very similar to the premutations problem but 
somewhat tricky we have to keep maintaining the index array so that we can track
that we are not dealing with the same element or not, so here if we find the same
element so we check if the visited of the element is ==0 and it is found once again
so we might as well skip that as the number similar to that has been covered earlier
and similarly following the backtracking concepts we move in the tree and do backtrack
accordingly
"""
class Solution:
    def permuteUnique(self, nums):
        nums.sort()
        ans = []
        index = [0]*(len(nums))
        if len(nums)==0:
            return []
        def backTrack(comb = []):
            if len(comb)==len(nums):
                ans.append(comb[:])
                return
            for i in range(0,len(nums)):
                if(index[i]==1): continue
                if(i>0 and nums[i-1]==nums[i] and index[i-1]!=1):
                    continue
                index[i]=1
                comb.append(nums[i])
                backTrack(comb)
                index[i]=0
                comb.pop()
        backTrack()
        return ans