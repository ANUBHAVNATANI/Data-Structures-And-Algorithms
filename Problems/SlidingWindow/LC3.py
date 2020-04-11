#Qusetion Link https://leetcode.com/problems/longest-substring-without-repeating-characters/
"""
Approch Sliding Window using the hash set add element and discard element if repeated 
and move the window and keep track of the max length
"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(len(s)==1):
            return 1
        elif(len(s)==0):
            return 0
        else:
            hash_set = set()
            maxlen = 0
            i,j = 0,0
            while(i<len(s) and j<len(s)):
                if(s[j] not in hash_set):
                    hash_set.add(s[j])
                    j+=1
                    maxlen = max(maxlen,j-i)
                else:
                    hash_set.discard(s[i])
                    i+=1
            return maxlen