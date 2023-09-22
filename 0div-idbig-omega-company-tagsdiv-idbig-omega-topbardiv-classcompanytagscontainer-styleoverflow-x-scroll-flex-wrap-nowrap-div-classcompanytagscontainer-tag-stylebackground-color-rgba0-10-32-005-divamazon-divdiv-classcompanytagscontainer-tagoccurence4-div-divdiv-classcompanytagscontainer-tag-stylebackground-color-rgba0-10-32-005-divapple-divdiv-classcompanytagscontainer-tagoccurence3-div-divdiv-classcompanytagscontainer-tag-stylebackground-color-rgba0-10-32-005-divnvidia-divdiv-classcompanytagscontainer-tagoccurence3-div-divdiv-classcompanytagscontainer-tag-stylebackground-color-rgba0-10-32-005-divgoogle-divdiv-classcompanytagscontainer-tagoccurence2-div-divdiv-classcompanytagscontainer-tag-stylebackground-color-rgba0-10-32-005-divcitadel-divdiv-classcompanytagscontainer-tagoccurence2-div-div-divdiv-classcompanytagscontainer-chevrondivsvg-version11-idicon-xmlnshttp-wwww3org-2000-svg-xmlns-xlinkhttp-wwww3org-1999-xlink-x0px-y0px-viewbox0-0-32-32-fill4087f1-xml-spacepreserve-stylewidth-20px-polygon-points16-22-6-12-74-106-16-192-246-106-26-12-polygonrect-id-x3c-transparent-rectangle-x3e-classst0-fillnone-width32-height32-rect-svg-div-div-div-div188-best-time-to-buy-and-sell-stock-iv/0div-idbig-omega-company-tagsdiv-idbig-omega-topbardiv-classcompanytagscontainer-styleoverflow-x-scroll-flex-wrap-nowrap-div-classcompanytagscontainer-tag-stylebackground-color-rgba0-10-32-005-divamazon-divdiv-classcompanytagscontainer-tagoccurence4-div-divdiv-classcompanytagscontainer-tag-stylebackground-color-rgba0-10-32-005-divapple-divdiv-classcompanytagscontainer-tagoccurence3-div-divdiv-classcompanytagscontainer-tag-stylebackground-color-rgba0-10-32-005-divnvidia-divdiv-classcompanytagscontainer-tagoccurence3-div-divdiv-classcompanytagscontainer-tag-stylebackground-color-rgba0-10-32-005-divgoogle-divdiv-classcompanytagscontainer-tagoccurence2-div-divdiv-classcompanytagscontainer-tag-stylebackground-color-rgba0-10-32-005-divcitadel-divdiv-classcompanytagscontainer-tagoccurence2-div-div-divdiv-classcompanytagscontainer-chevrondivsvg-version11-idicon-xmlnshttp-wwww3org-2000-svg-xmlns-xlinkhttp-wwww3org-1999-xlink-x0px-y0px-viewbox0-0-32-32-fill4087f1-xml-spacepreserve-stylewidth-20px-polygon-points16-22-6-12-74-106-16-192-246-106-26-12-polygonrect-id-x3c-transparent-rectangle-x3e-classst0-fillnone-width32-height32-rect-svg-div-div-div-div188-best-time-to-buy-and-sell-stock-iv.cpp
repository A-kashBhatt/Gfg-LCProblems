//tabulation solution
class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        int sz=prices.size();
        vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind=sz-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                for(int trades=k;trades>0;trades--){
                    if(buy){
                       dp[ind][buy][trades]=max(-prices[ind]+ dp[ind+1][0][trades], dp[ind+1][1][trades]);
            }
                    
                    else{
                        dp[ind][buy][trades]= max(prices[ind]+ dp[ind+1][1][trades-1], dp[ind+1][0][trades]);
            }
                    }
                }
            }
        
        return dp[0][1][k];
    }
};