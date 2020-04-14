#https://leetcode.com/problems/palindrome-partitioning/
"""
As this is a backtracking question, we can approch the problem
very similar to the combination or permutation promblem iteratively
moving the tree and finding and forming the pallendromes and adding them
to the answers
"""
class Solution:
    def partition(self, s: str):
        ans = []
        def backTrack(idx=0,comb=[]):
            if(idx==len(s)):
                ans.append(comb[:])
            for i in range(idx,len(s)):
                if(s[idx:i+1]==s[idx:i+1][::-1]):
                    backTrack(i+1,comb+[s[idx:i+1]])
        backTrack()
        return ans