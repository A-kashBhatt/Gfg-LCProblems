//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{  void helper(vector<int>& A,int i,int n,vector<int>&v,vector<vector<int>>&soln){
    if(i==n){
        soln.push_back(v);
        return;
    }
    v.push_back(A[i]);
    helper(A,i+1,n,v,soln);
    v.pop_back();
    helper(A,i+1,n,v,soln);
   }
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {  
        vector<vector<int>>soln;
        vector<int>v;
        helper(A,0,A.size(),v,soln);
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
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends