#https://leetcode.com/problems/product-of-array-except-self/
"""
We can do it without multiplication by forming two arrays
first is multiplying the left side and multiplying the right
side and these we can see from these two arrays we can 
find the multiplication using the two arrays and we can
do it in O(1) space make one array on the fly and one array
using the output array
"""
class Solution:
    def productExceptSelf(self, nums):
        op = []
        s = 1
        for i in range(len(nums)):
            s*=nums[i]
            op.append(s)
        #op contains the left product
        temp = 1
        for j in range(len(nums)-1,-1,-1):
            if j==0:
                op[j] = temp
            elif j==len(nums)-1:
                op[j] = op[j-1]
            else:
                op[j] = temp*op[j-1]
            temp*=nums[j]
        return op