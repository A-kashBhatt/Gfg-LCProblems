//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        int ans=0,sz1=n,sz2=m,x=0,prevVar=0,currVar=0;;
        vector<int>prev(sz2,0); 
	for(int i=0;i<sz1;i++){
		for(int j=0;j<sz2;j++){
			currVar=prev[j];
			if(s[i]==t[j]){
				if(j-1>=0)prev[j]=1+prevVar;
				else prev[j]=1;
				ans=max(ans,prev[j]);
			}
			else{
				prev[j]=0;
			}
			prevVar=currVar;
		}
		prevVar=0;
	}
	return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends