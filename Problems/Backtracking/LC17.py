#https://leetcode.com/problems/letter-combinations-of-a-phone-number/
"""
In this question we are trying to implement a backtracking solution
it is more like recursion here, we are trying to make all possible pairs 
using the recursion first we pick the first letter and then
pick all the alternative of the other along with it and in simlar fashion
growing the recusion tree
"""
class Solution:
    def helperFunc(self,c,n):
        if len(n)==0:
            self.ans.append(c)
        else:
            for l in self.hm[n[0]]:
                self.helperFunc(c+l,n[1:])
    
    def letterCombinations(self, digits: str):
        self.hm = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z']}
        self.ans = []
        if len(digits)>0:
            self.helperFunc("",digits)
        return self.ans