//memoization 
class Solution {
    // int helper(vector<int>& nums,int ind,int lastInd,vector<vector<int>>&dp){
    //     if(ind<0)return 0;
    //     if(dp[ind][lastInd]!=-1)return dp[ind][lastInd];
    //     if(lastInd==nums.size()){
    //         return dp[ind][lastInd]=max(1+helper(nums,ind-1,ind,dp), helper(nums,ind-1,lastInd,dp));
    //     }
    //     if(nums[ind]<nums[lastInd]){
    //         return dp[ind][lastInd]=max(1+helper(nums,ind-1,ind,dp), helper(nums,ind-1,lastInd,dp));
    //     }
    //     else{
    //         return dp[ind][lastInd]=helper(nums,ind-1,lastInd,dp);
    //     }
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)dp[i][0]=1;
    for(int ind=1;ind<=n;ind++){
        for(int lastInd=1;lastInd<=n;lastInd++){
           if(lastInd==n || nums[ind-1]<nums[lastInd]){
            dp[ind][lastInd]= max(1+dp[ind-1][ind-1],dp[ind-1][lastInd]);
           } 
           else{
            dp[ind][lastInd]=dp[ind-1][lastInd];
           }
        }
    }
    return dp[n][n];
    }
};