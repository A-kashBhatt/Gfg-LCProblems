//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
  public:
    int cutRod(int price[], int n) {
        vector<int>prev(n+1,0);
        // for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++)prev[i]=price[0]*i;
        for(int ind=1;ind<n;ind++){
            for(int l=1;l<=n;l++){
                int cut=INT_MIN;
                if(l>=ind+1)cut=price[ind]+prev[l-(ind+1)];
                prev[l]=max(cut,prev[l]); 
            }
        }
        return prev[n];
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