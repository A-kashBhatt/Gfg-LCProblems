//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{   
    int lcs(string s, string t) {
        int sz1=s.size(),sz2=t.size(),x=0,prevVar=0,currVar=0;
	vector<int>prev(sz2,0); 
	for(int i=0;i<sz1;i++){
		for(int j=0;j<sz2;j++){
			currVar=prev[j];
			if(s[i]==t[j]){
				if(j-1>=0)prev[j]=1+prevVar;
				else prev[j]=1;
			}
			else{
				int a=0;
				if(j-1>=0)a=prev[j-1];
				prev[j]=max(a,prev[j]);
			}
			prevVar=currVar;
		}
		prevVar=0;
	}
	return prev[sz2-1];
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return (m+n-lcs(X,Y));
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends