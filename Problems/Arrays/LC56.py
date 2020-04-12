#https://leetcode.com/problems/merge-intervals/
"""
Simple Array manupulation question we have to keep tarck of the 
intervals which are going to be merge together.
"""
class Solution:
    def merge(self, intervals):
        ans = []
        if len(intervals)==0:
            return ans
        intervals.sort()
        si = intervals[0]
        for i in range(1,len(intervals)):
            if intervals[i][0]<=si[1]:
                si[1] = max(intervals[i][1],si[1])
            else:
                ans.append(si)
                si = intervals[i]
        ans.append(si)
        return ans