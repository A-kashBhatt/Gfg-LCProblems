//memoization solution
class Solution {
 
public:
    int change(int value, vector<int>& coins) {
        
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<long>prev(value+1,0);
        prev[0]=1;
        for(int i=1;i<=value;i++)if(i%coins[0]==0)prev[i]=1;
     for(int i=1;i<n;i++){
        for(int j=1;j<=value;j++){
          long take=0;
          if(j>=coins[i])take=prev[j-coins[i]];
          prev[j]+=take;
        }
    }
    return prev[value];
        
    }
};