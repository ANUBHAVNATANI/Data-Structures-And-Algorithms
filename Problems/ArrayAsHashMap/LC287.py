#https://leetcode.com/problems/find-the-duplicate-number/
"""For doing these type of questions we in O(1) space we generally use the 
array index as the hash for storing the element frequency
"""
from math import floor
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        maxR = len(nums)-1
        for i in range(len(nums)):
            tempVal = nums[i]
            if(tempVal>maxR):
                if(tempVal%maxR!=0):
                    tempVal = nums[i]-(tempVal//maxR)*maxR
                else:
                    tempVal = nums[i]-((tempVal//maxR)-1)*maxR
            nums[tempVal-1]+=maxR
        return nums.index(max(nums))+1