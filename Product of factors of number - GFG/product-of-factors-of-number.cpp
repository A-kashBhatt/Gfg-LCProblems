//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    int modulo=1e9+7;
  public:
    int factorProduct(int N) {
        int product=1;
        for(int i=1;i*i<=N;i++){
            if(N%i==0){
                product=((long long)product*i)%modulo;
                if(i!=(N/i))product=((long long)product*(N/i))%modulo;
            }
            
        }
        return product;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.factorProduct(N) << "\n";
    }
}
// } Driver Code Ends