//0 ->buy 1->sell 2->cool down --------->repeat this cycle
class Solution {
    int helper(vector<int>& prices,int ind,int sz,int token,vector<vector<int>>&dp){
        if(ind==sz)return 0;
        if(dp[ind][token]!=-1)return dp[ind][token];
        if(token==0){//buy
            return dp[ind][token]=max(-prices[ind]+ helper(prices,ind+1,sz,token+1,dp),
                    helper(prices,ind+1,sz,token,dp));
        }
        else if(token==1){//sell
             return dp[ind][token]=max(prices[ind]+helper(prices,ind+1,sz,token+1,dp),
                    helper(prices,ind+1,sz,token,dp));
        }
        else{//cooldown peroid
            return dp[ind][token]=helper(prices,ind+1,sz,0,dp);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        vector<vector<int>>dp(sz,vector<int>(3,-1));
        return helper(prices,0,sz,0,dp);
    }
};