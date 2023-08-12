//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    int a[]=new int[n];
		    
		    for(int i=0;i<n;i++)
		    {
		        a[i]=sc.nextInt();
		    }
		    int m=sc.nextInt();
		    Solution ob = new Solution();
		    System.out.println(ob.findPages(a,n,m));
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution 
{
     public static int helper(int[] A,int k){
        int count=1;
        int prefix=0;
        for(int i:A){
            prefix+=i;
            if(prefix>k){
                prefix=i;
                count++;
            }
        }
        return count;
    }
    public static int findPages(int[]A,int N,int M)
    {   if(M>N)return -1;
        int min=Integer.MIN_VALUE;
        int max=0,ans=-1;
        for(int i:A){
            min=Math.max(i,min);
            max+=i;
        }
        while(min<=max){
            int mid=(min+max)/2;
            int students=helper(A,mid);
            if(M<students){
                min=mid+1;
            }
            else{
                ans=mid;
                max=mid-1;
            }
        }
        return ans;
    }
};