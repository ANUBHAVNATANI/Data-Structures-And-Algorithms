/*
Qusetion Link https://leetcode.com/problems/longest-substring-without-repeating-characters/

Approch Sliding Window using the hash set add element and discard element if repeated 
and move the window and keep track of the max length
*/
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int los = s.length(),maxLen = 0;
        HashSet<Character> hs = new HashSet<>();
        int i=0,j=0;
        while(i<los && j<los){
            if(!hs.contains(s.charAt(j))){
                hs.add(s.charAt(j));
                j++;
                maxLen = Math.max(j-i,maxLen);
            }
            else{
                hs.remove(s.charAt(i));
                i++;
            }
        }
        return maxLen;
    }
}