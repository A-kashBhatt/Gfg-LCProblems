//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isValid(vector<int> &stalls, int k,int m){
    int last=stalls[0],n=stalls.size(),cnt=1;
    for(int i=1;i<n;i++){
        if((stalls[i]-last) >=m){
            cnt++;
            last=stalls[i];
            if(cnt>=k)return true;
        }
    }
    return false;
}

public:

    int solve(int n, int k, vector<int> &stalls) {
    
    sort(stalls.begin(),stalls.end());
    int e=stalls[n-1]-stalls[0];
    int s=1,soln;
    while(e>=s){
        int m=s+(e-s)/2;
        if(isValid(stalls,k,m)){
            soln=m;
            s=m+1;
        }
        else e=m-1;
    }
    return soln;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends