class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int s=0,sz=arr.size(),e=sz-1;
        if(sz==1)return 0;
        while(e>=s){
            int mid=s+(e-s)/2;
            if(mid==0) return arr[mid]>arr[mid+1]?0:1;
            if(mid==sz-1) return arr[mid]>arr[mid-1]?mid:mid-1;
            
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            else if(arr[mid]<arr[mid-1])e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
};