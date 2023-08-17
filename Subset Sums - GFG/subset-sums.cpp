//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    void helper(vector<int> &arr, int N,int currSum,int i,vector<int>&soln){
        if(i==N){
            soln.push_back(currSum);
            return;
        }
        //taking it
        helper(arr,N,currSum+arr[i],i+1,soln);
        //not taking it
        helper(arr,N,currSum,i+1,soln);
    }
public:
    vector<int> subsetSums(vector<int> &arr, int N)
    {
        vector<int>soln;
        helper(arr,N,0,0,soln);
        sort(soln.begin(),soln.end());
        return soln;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends