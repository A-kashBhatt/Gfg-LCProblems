//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0;
        long long product=1;
        int i=0,j=0;//i->>>>>>>>>left. &.   j->>>>>>>>>>>right
        
        while(j<n){
            product=product*a[j];
            if(product<k){
                ans+=(j-i+1);
                j++;
            }
            else{
                while(1){
                    product/=a[i];
                    i++;
                    if(i>j)break;
                    if(product<k){
                       ans+=(j-i+1);
                       break;
                    }
                }
                
                j++;
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends