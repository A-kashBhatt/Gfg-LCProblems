//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    int longestCommonSubsequence(string s, string t) {
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
	int minOperations(string str1, string str2) 
	{ 
	    return abs(str1.size()+str2.size()-2*longestCommonSubsequence(str1,str2));
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends