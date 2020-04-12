#https://leetcode.com/problems/combination-sum-ii/
"""
Backtracking question as all the combination are needed to be formed 
we have to keep making the combination until we reach a negative target if 
we move to a negative target we go back so we write a pop there
and we make all the combination untill we all the ans are found
"""
class Solution:
    def helperFunc(self,target,start,combination=[]):
        if target<0:
            return
        elif target==0:
            self.ans.append(combination[:])
            return
        else:
            for i in range(start,len(self.cand)):
                if(i>start and self.cand[i-1]==self.cand[i]):continue
                combination.append(self.cand[i])
                self.helperFunc(target-self.cand[i],i+1,combination)
                #going back to the previous step
                combination.pop()
    def combinationSum2(self, candidates, target):
        self.ans = []
        self.cand = sorted(candidates)
        self.helperFunc(target,0)
        return self.ans