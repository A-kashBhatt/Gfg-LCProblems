//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	ll countSubarray(int arr[], int n, int k) {
	    long long int soln=0,temp=n,p=-1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>k){
	         long long int l,r;
	         if((i==p+1) || (i==n-1)){
	             soln=soln+n-p-1;
	             p=i;
	             continue;
	         }
	         l=(i-p);
	         r=(n-i-1);
	         
	         soln=soln+l+r+(l-1)*r;
	         p=i;
	        }
	    }
	    return soln;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends