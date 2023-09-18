class Solution {
   
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0),curr(n,0);
        curr[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int top=0,left=0;
                if(i-1>=0)top=prev[j];
                if(j-1>=0)left=curr[j-1];
                curr[j]=top+left;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};