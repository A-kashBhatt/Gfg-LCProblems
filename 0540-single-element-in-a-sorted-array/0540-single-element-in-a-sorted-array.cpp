class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s=0,sz=arr.size(),e=sz-1;
        while(e>=s){
            int mid=s+(e-s)/2;
            if(mid==0 || mid==(sz-1))return arr[mid];
            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])return arr[mid];
            if(arr[mid]==arr[mid+1]){
                if((mid+1)%2)s=mid+2;
                else e=mid-1;
            }
            if(arr[mid]==arr[mid-1]){
                if(mid%2)s=mid+1;
                else e=mid-2;
            }
        }
        return -1;
    }
};