//https://leetcode.com/problems/combination-sum-ii/
/*
"""
Backtracking question as all the combination are needed to be formed 
we have to keep making the combination until we reach a negative target if 
we move to a negative target we go back so we write a pop there
and we make all the combination untill we all the ans are found
"""
*/
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(ans,new ArrayList<>(),candidates,target,0);
        return ans;
    }
    public void backtrack(List<List<Integer>> ans,List<Integer> combination,int[] candidates,int target,int index){
        if(target<0) return;
        else if (target==0) ans.add(new ArrayList<>(combination));
        else{
            for(int i=index;i<candidates.length;i++){
                if(i>index && candidates[i-1]==candidates[i]) continue;
                combination.add(candidates[i]);
                backtrack(ans,combination,candidates,target-candidates[i],i+1);
                combination.remove(combination.size()-1);
            }
        }
    }
}