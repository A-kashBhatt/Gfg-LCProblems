//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{    bool isValid(int A[],int N,int M,int m){
     int student=1,sum=0;
     for(int i=0;i<N;i++){
         sum+=A[i];
         if(sum>m){
             student++;
             sum=A[i];
             if(student>M)return false;
         }
     }
     return true;
     }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int s=*max_element(A,A+N);
        int e=accumulate(A,A+N,0);
        int soln=-1;
        if(M>N)return -1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(isValid(A,N,M,m)){
                soln=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return soln;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends