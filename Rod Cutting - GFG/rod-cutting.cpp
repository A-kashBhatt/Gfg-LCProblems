//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int helper(int price[],int ind,int l,vector<vector<int>>&dp){
        if(l==0 || ind==-1)return 0;
        if(dp[ind][l]!=-1)return dp[ind][l];
        int cut=INT_MIN;
        if(l>=ind+1)cut=price[ind]+helper(price,ind,l-(ind+1),dp);
        int notCut=helper(price,ind-1,l,dp);
        return dp[ind][l]=max(cut,notCut);
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends