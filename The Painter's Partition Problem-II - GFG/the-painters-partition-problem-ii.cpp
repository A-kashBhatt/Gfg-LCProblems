//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
bool isValid(int arr[], int n, int k,long long int m){
    long long int p=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>m){
            p++;
            sum=arr[i];
            if(p>k)return false;
        }
    }
    return true;
}
class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long int s=*max_element(arr,arr+n),e=accumulate(arr,arr+n,(long long)0);
        long long int soln=e;
        while(e>=s){
            long long int m=s+(e-s)/2;
            if(isValid(arr,n,k,m)){
                soln=m;
                e=m-1;
            }
            else s=m+1;
        }
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends