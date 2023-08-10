//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int maxStairHeight(int N) {
        int value=(int)sqrt(2*N);
        if(value*(value+1)<=2*N)return value;
        return value-1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.maxStairHeight(N) << endl;
    }
    return 0;
}
// } Driver Code Ends