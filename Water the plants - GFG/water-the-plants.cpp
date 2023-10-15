//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
       vector<pair<int,int>>ranges;
       for(int i=0;i<n;i++){
           if(gallery[i]!=-1)
           ranges.push_back({max(0,i-gallery[i]),min(n-1,i+gallery[i])});
       }
       sort(ranges.begin(),ranges.end());
       int start=0,ans=0,i=0,last=-1;
       int sz=ranges.size();
       while(i<sz){
           int lastLast=last;
           ans++;
           while(i<sz && ( start>ranges[i].second || (ranges[i].first<=start) && (ranges[i].second>=start))){
               last=max(last,ranges[i].second);
               i++;
           }
           if(last==n-1)return ans;
           if(lastLast==last)return -1;
           start=last+1;
       }
       return -1;
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends