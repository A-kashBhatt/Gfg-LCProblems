//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans=(*max_element(arr,arr+n)-*min_element(arr,arr+n));
        for(int i=0;i<n-1;i++){
            int tempMax=max(arr[i]+k,arr[n-1]-k);
            int tempMin=min(arr[0]+k,arr[i+1]-k);
            if(tempMin<0)continue;
            ans=min(ans,tempMax-tempMin);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends