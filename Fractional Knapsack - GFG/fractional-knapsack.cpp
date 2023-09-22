//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        if(double(p1.first/(1.0*p1.second))>double(p2.first/(1.0*p2.second)))return true;
        return false;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i].value,arr[i].weight});
        }
        sort(v.begin(),v.end(),comp);
        double gain=0;
        for(int i=0;i<n;i++){
            if(v[i].second<=W){
                W-=v[i].second;
                gain+=v[i].first;
            }
            else{
                gain+=(W*((double)v[i].first/v[i].second));
                return gain;
            }
        }
        return gain;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends