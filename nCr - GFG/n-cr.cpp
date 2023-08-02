//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{
    ll mod=1e9+7;
    ll findPower(ll base, ll power){
        
        if(power == 0)
            return 1;
        
        ll powerHalf = findPower(base,power/2);
        
        if(power%2 == 0)
            return (powerHalf*powerHalf)%mod;
        else
            return (base*((powerHalf*powerHalf)%mod))%mod;
        
        
    }
    ll factorial(ll a){
        ll soln=1;
        for(int i=2;i<=a;i++){
          soln=(soln%mod*i)%mod;
        } 
        return soln;
    }
public:
    long int ncr(int n, int r){
        if(r>n)return 0;
        ll a=factorial(n);
        ll b=factorial(r);
        ll c=factorial(n-r);
        
         b= (b*c)%mod;
        ll bin= (findPower(b,mod-2))%mod;
        ll soln= ((a%mod) * (bin%mod))%mod;
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
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.ncr(n, r) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends