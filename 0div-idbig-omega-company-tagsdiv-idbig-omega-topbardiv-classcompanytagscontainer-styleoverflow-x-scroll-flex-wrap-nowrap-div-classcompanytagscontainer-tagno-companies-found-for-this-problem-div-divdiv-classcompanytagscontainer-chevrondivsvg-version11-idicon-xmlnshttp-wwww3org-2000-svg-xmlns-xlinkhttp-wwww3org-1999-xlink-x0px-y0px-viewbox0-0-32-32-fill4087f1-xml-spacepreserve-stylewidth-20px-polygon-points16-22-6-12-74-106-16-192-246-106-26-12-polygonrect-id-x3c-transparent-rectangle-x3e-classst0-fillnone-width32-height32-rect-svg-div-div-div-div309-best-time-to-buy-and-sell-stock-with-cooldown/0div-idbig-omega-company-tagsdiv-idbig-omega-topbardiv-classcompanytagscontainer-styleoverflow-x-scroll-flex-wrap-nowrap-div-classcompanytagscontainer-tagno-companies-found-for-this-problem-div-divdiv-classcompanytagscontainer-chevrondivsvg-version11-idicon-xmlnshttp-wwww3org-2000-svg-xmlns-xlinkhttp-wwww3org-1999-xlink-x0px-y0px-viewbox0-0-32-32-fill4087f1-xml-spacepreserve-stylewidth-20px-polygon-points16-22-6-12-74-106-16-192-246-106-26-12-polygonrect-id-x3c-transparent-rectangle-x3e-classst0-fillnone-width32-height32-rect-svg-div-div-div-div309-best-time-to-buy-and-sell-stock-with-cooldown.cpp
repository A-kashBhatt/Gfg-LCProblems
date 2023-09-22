//0 ->buy 1->sell 2->cool down --------->repeat this cycle

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        vector<vector<int>>dp(sz+1,vector<int>(3,0));
        for(int ind=sz-1;ind>=0;ind--){
            for(int token=0;token<3;token++){
              if(token==0){//buy
               dp[ind][token]=max(-prices[ind]+dp[ind+1][(token+1)%3],
                    dp[ind+1][token]);
              }  
              else if(token==1){
                dp[ind][token]=max(prices[ind]+dp[ind+1][(token+1)%3],
                    dp[ind+1][token]); 
              } 
              else{
                dp[ind][token]=dp[ind+1][(token+1)%3];
              }
            }
        }
        return dp[0][0];
    }
};