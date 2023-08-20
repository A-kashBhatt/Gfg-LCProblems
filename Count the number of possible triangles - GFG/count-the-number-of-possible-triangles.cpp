//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
  //Function to count the number of possible triangles.
  int findNumberOfTriangles (int arr[], int n)
  {
    int cnt = 0;
      sort (arr, arr + n);
    int k = n - 1;
    while (k >= 2)
      {
	int j = k - 1,i=0;
	while (j > i)
	  {
	    if (arr[i] + arr[j] > arr[k])
	      {
		cnt += (j - i);
		j--;
	      }
	    else
	        i++;
	  }
	k--;
      }
    return cnt;

  }
};



//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends