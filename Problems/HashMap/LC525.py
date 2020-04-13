#https://leetcode.com/problems/contiguous-array/
"""
Basic idea is to make the question as we have to find the contiguous array with zero
sum so we do a -1 when we find 0 and +1 when we find 1 and we find if sum repappers 
or 0 comes as sum we return max of those. That's it.
"""
class Solution():
    def findMaxLength(self, nums):
        hm = {}
        s = 0
        maxLen = float('-inf')
        for i in range(len(nums)):
            if(nums[i]==0):
                s-=1
                if s in hm:
                    if s==0:
                        hm[0] = i
                    maxLen = max(i-hm[s],maxLen)
                else:
                    hm[s] = i
            else:
                s+=1
                if s in hm:
                    if s==0:
                        hm[0] = i
                    else:
                        maxLen = max(i-hm[s],maxLen)
                else:
                    hm[s] = i
        if 0 in hm:
            return max(maxLen,hm[0]+1)
        else:
            return max(maxLen,0)