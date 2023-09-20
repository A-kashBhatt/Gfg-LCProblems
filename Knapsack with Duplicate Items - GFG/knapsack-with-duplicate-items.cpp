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
       vector<int>prev(W+1,0);
       prev[0]=0;
       if(wt[0]<=W){
           for(int j=wt[0];j<=W;j++){
              prev[j]=(j/wt[0])*val[0];
           }
       }
       for(int i=1;i<n;i++){
           for(int j=1;j<=W;j++){
               int take=INT_MIN;
               if(wt[i]<=j)take=val[i]+prev[j-wt[i]];
               prev[j]=max(take,prev[j]);
           }
       }
       return prev[W];
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