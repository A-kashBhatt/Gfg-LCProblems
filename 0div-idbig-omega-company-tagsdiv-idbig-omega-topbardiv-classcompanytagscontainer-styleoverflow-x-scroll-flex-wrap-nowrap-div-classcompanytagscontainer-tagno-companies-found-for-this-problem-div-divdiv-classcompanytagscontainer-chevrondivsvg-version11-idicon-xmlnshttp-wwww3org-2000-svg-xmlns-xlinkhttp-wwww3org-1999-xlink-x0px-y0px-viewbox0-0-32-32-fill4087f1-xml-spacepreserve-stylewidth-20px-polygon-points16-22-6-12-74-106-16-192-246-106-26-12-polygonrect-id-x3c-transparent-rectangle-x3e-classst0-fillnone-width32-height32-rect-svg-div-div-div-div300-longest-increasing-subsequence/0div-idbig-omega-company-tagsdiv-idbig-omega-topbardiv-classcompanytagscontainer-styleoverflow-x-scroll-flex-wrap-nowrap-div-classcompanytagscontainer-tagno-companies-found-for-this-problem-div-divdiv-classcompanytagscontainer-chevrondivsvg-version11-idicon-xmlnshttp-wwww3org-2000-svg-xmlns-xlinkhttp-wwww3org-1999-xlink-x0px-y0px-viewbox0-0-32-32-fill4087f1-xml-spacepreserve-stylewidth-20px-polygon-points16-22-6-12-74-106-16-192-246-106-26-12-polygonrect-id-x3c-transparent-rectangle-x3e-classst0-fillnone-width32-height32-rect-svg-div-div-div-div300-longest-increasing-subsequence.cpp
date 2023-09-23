//memoization 
class Solution {
    int helper(vector<int>& nums,int ind,int lastInd,vector<vector<int>>&dp){
        if(ind<0)return 0;
        if(dp[ind][lastInd]!=-1)return dp[ind][lastInd];
        if(lastInd==nums.size()){
            return dp[ind][lastInd]=max(1+helper(nums,ind-1,ind,dp), helper(nums,ind-1,lastInd,dp));
        }
        if(nums[ind]<nums[lastInd]){
            return dp[ind][lastInd]=max(1+helper(nums,ind-1,ind,dp), helper(nums,ind-1,lastInd,dp));
        }
        else{
            return dp[ind][lastInd]=helper(nums,ind-1,lastInd,dp);
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz=nums.size();
        vector<vector<int>>dp(sz,vector<int>(sz+1,-1));
        return helper(nums,sz-1,sz,dp);
    }
};