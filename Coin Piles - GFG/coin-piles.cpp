//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int n, int k) {
       sort(A,A+n);
       int ans=INT_MAX;
       vector<int>prefix(n,0);
       prefix[0]=A[0];
       for(int i=1;i<n;i++){
           prefix[i]=prefix[i-1]+A[i];
       }
       for(int i=0;i<n;i++){
           int temp=0;
           if(i>0)temp+=prefix[i-1];
           int idx=upper_bound(A,A+n,A[i]+k)-A;
           temp+=((prefix[n-1]-prefix[idx-1])-(n-idx)*(A[i]+k));
           ans=min(ans,temp);
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends