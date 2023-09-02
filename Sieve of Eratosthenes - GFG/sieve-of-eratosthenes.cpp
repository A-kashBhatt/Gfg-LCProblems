//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {   vector<bool>v(N+1,true);
        for(int i=2;i*i<=N;i++){
            int j=2;
            while(i*j<=N){
                v[i*j]=false;
                j++;
            }
        }
        vector<int>soln;
        for(int i=2;i<=N;i++){
            if(v[i])soln.push_back(i);
        }
        return soln;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends