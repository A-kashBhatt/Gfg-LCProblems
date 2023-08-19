//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

int partition (int arr[], int low, int high)
    {
    int pivot = arr[high];
    int j = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j + 1], arr[high]);
    return j + 1;
}

int quickSelect(int arr[],int low,int high,int k){
    int pivot=partition(arr,low,high);
    if(pivot==k-1)return arr[pivot];
    else if(pivot>k-1) {return quickSelect(arr,low,pivot-1,k);}
    else  { return quickSelect(arr,pivot+1,high,k);}
}

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int index=quickSelect(arr,l,r,k);
    }
};


//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends