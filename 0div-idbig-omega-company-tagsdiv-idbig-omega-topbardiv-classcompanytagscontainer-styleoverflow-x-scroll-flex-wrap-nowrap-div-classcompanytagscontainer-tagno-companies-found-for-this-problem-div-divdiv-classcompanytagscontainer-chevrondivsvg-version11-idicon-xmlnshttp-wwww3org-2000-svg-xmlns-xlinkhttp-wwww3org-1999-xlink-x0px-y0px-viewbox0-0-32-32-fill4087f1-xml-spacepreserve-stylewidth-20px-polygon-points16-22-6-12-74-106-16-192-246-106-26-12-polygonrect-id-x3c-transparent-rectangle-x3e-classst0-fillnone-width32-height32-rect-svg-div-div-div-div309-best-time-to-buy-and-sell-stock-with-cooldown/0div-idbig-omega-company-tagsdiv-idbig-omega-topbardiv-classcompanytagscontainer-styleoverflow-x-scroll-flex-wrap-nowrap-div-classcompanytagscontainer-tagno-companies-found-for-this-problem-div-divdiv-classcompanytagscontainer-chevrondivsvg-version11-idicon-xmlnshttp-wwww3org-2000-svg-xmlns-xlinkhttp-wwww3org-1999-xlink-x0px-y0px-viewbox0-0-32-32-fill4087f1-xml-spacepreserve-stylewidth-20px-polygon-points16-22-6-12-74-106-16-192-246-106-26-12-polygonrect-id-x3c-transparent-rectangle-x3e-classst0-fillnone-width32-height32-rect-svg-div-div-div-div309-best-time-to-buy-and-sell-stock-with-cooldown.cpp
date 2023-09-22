//0 ->buy 1->sell 2->cool down --------->repeat this cycle

//tabulation with space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        vector<int>curr(3,0),ahead(3,0);
        for(int ind=sz-1;ind>=0;ind--){
            for(int token=0;token<3;token++){
              if(token==0){//buy
               curr[token]=max(-prices[ind]+ahead[(token+1)%3],
                    ahead[token]);
              }  
              else if(token==1){
                curr[token]=max(prices[ind]+ahead[(token+1)%3],
                    ahead[token]); 
              } 
              else{
                curr[token]=ahead[(token+1)%3];
              }
            }
            ahead=curr;
        }
        return ahead[0];
    }
};