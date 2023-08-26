//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{  
    bool isPossible(vector<vector<int>>& matrix,int mid,int k){
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            cnt+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
        }
        return cnt>=k;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=INT_MAX,high=INT_MIN,ans;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        int k=(R*C)/2+1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(isPossible(matrix,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;       
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends