#https://leetcode.com/problems/word-break/
"""
At first we seem to do this question using greedy as match as we find the word
but with the test case like catsanddogs we can't do it we have to store
somehow if chossing that word will lead to the correct decision, Choice of 
words comes from the fact to chose that or not form some of the basis of dp
This kind of problems are a part of dp so we first choose 
iterate through the i and then look at each word to find the if that is 
possible using curret i and look at the back index of it if it has been found till yet
or not.
"""
class Solution:
    def wordBreak(self, s: str, wordDict) -> bool:
        dp = [False]*(len(s)+1)
        dp[0] = True
        for i in range(1,len(s)+1):
            for j in wordDict:
                if len(j)<=i:
                    if(dp[i-len(j)]):
                        if(s[i-len(j):i]==j):
                            dp[i] = True
                            break
                else:
                    pass
        return True if(dp[-1]) else False