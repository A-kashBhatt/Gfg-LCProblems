//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int sz, vector<int>& nums) {
        int endInd=sz-1,maxi=1;
        vector<int>dp(sz,1),parent(sz,-1);
        for(int i=1;i<sz;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j] && dp[i]<=1+dp[j]){
                    dp[i]=1+dp[j];
                    if(parent[i]==-1 || nums[parent[i]]<nums[j])
                    parent[i]=j;      
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                endInd=i;
            }
        }
        vector<int>soln;
        while(endInd!=-1){
            soln.push_back(nums[endInd]);
            endInd=parent[endInd];
        }
        reverse(soln.begin(),soln.end());
        return soln;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends