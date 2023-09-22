//memoization
class Solution {
    int helper(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp,int fee){
        if(ind==prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
          return  dp[ind][buy]=max(-prices[ind]+helper(prices,ind+1,0,dp,fee),
                     helper(prices,ind+1,1,dp,fee));
        }
        else{
          return  dp[ind][buy]=max(prices[ind]-fee+helper(prices,ind+1,1,dp,fee),
                     helper(prices,ind+1,0,dp,fee));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(prices,0,1,dp,fee);
    }
};