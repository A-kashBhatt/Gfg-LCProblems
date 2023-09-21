//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        // for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++)dp[0][i]=price[0]*i;
        for(int ind=1;ind<n;ind++){
            for(int l=1;l<=n;l++){
                int cut=INT_MIN;
                if(l>=ind+1)cut=price[ind]+dp[ind][l-(ind+1)];
                int notCut=dp[ind-1][l];
                dp[ind][l]=max(cut,notCut); 
            }
        }
        return dp[n-1][n];
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