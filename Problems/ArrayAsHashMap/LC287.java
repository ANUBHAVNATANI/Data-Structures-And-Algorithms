/*
https://leetcode.com/problems/find-the-duplicate-number/
For doing these type of questions we in O(1) space we generally use the 
array index as the hash for storing the element frequency
*/
class Solution {
    public int findDuplicate(int[] nums) {
        int maxR = nums.length-1;
        int tempVal;
        for(int i=0;i<=maxR;i++){
            tempVal = nums[i];
            if(tempVal>maxR){
                if(tempVal%maxR!=0)tempVal=nums[i]-(tempVal/maxR)*maxR;
                else tempVal = nums[i]-((tempVal/maxR)-1)*maxR;
            }
            nums[tempVal-1]+=maxR;
        }
        int maxVal = Arrays.stream(nums).max().getAsInt();
        for(int i=0;i<nums.length;i++){
            if(nums[i]==maxVal) return i+1;
        }
        return -1;
    }
}