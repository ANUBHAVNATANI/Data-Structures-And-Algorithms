# https://leetcode.com/problems/generate-parentheses 
"""
In this type of question generally the recursion tree decreases using some
constrints we also have the choice of brach into some of the braches of the 
recursion tree or not finally we store the result
Backtracking approch like that find the ways to reduce the recursion tree 
which is generally going exponential
In this question we can keep tarck of the open bracket to see if we can close the 
bracket now or not and that's why we will not have to implement a function to check
if a bracket is valid or not
"""
class Solution:
    def helperFunc(self,S="",l=0,r=0):
        #if the string length is equal to the 2*n(total number of brackets we have)
        if len(S)==2*self.n:
            self.ans.append(S)
            return
        if l<self.n:
            self.helperFunc(S+"(",l+1,r)
        if r<l:
            self.helperFunc(S+")",l,r+1)
        
    def generateParenthesis(self, n):
        self.ans = []
        self.n = n
        self.helperFunc()
        return self.ans