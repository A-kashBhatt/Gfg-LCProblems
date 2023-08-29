//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>s;
        vector<long long>soln;
        for(int i=arr.size()-1;i>=0;i--){
            while(s.size()>0 && s.top()<=arr[i])s.pop();
            if(s.empty()){
                soln.push_back(-1);
            }
            else soln.push_back(s.top());
            s.push(arr[i]);
        }
        reverse(soln.begin(),soln.end());
        return soln;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends