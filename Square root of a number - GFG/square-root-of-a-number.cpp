//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
    bool isValid(long long int x,int mid){
        if((long long)mid*mid>=x)return true;
        return false;
    }
  public:
    long long int floorSqrt(long long int x) 
    {
        int low=1,high=x,ans=0;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(isValid(x,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans*ans>x?ans-1:ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends