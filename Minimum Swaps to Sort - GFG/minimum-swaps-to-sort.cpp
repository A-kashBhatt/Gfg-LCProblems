//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>>v;
	    int sz=nums.size();
	    for(int i=0;i<sz;i++){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int cnt=0;
	    for(int i=sz-1;i>=0;i--){
	        if(v[i].second==i)continue;
	        else{
	            swap(v[i].second,v[v[i].second].second);
	            cnt++;
	            i++;
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends