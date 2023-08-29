//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
       vector<int>soln;
       stack<int>s;
       int sz=arr.size();
       for(int i=sz-1;i>=0;i--){
           while(s.size()>0 && s.top()>=arr[i])s.pop();
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends