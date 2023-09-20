//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int i=0;i<n;i++)dp[i][0]=0;
       if(wt[0]<=W){
           for(int j=wt[0];j<=W;j++){
              dp[0][j]=(j/wt[0])*val[0];
           }
       }
       for(int i=1;i<n;i++){
           for(int j=1;j<=W;j++){
               int take=INT_MIN;
               if(wt[i]<=j)take=val[i]+dp[i][j-wt[i]];
               int notTake=dp[i-1][j];
               dp[i][j]=max(take,notTake);
           }
       }
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends