//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    long long gcd(long long int x,long long int y){
        if(y==0)return x;
        return gcd(y,x%y);
    }
public:
    long long findValue(int x, int y, int z) { 
        long long int l1=x/gcd(x,y)*y;
        long long int l2=x/gcd(x,z)*z;
        return gcd(l1,l2);
    }
        
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        Solution ob;
        cout << ob.findValue(x, y, z) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends