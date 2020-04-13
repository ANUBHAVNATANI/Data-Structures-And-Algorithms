#https://leetcode.com/problems/permutations/
"""
As we have to generate all the permutations we can use backtracking
create ans to store the resulting array it will go like
[1] - > [1,2] - > [1,2,3] as it will ignore 1,2 by that continue ans similarly
backtrack and make solution
"""
class Solution:
    def permute(self, nums):
        #direct solution using python standard library
        # from itertools import permutations
        # return map(list, itertools.permutations(nums))
        # Map is used to make it list of list, insted of list of tuples
        ans = []
        if len(nums)==0:
            return []
        def backTrack(comb = []):
            if len(comb)==len(nums):
                ans.append(comb[:])
                return
            for i in range(0,len(nums)):
                if nums[i] in comb: continue
                comb.append(nums[i])
                backTrack(comb)
                comb.pop()
        backTrack()
        return ans