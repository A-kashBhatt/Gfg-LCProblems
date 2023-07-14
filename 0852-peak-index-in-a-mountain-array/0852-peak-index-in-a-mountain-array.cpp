class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        int n=arr.size()-1;
        while(e>=s){
            int m=s+(e-s)/2;
            if(arr[m]>arr[m+1] && arr[m]>arr[m-1])return m;
            if(arr[m]<arr[m+1]) s=m+1;
            else e=m-1;
        }
        return -1;
    }
};