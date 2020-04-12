from itertools import combinations
#https://leetcode.com/problems/combinations/
"""
Similar to the subset problem just we have to form
the combination of limited size
"""
class Solution:
    def combine(self, n: int, k: int):
        # ans = []
        # if n==0 or k==0:
        #     return []
        # def backTrack(ind=0,comb = []):
        #     if len(comb)==k:
        #         ans.append(comb[:])
        #         return
        #     for i in range(ind,n):
        #         backTrack(i+1,comb+[i+1])
        # backTrack()
        # return ans
        return list(combinations(range(1, n+1), k))