#https://leetcode.com/problems/3sum/
"""
It is a slight modified version of 2sum and we can fix one number and then move two
pointes like 2sum and generally two pointers work with sorted array
"""

class Solution:
    def threeSum(self, nums):
        nums.sort()
        a = []
        for i in range(len(nums)-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            l,r = i+1,len(nums)-1
            while(l<r):
                s = nums[i]+nums[l]+nums[r]
                if(s<0):
                    l+=1
                elif(s>0):
                    r-=1
                else:
                    a.append([nums[i],nums[l],nums[r]])
                    while(l<r and nums[l]==nums[l+1]):
                        l+=1
                    while(l<r and nums[r]==nums[r-1]):
                        r-=1
                    l+=1;r-=1
        return a