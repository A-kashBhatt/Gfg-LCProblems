class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>prev(n,1e9),curr(n,0);
        curr[0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int a=INT_MAX,b=INT_MAX;
                if(i-1>=0)a=grid[i][j]+prev[j];
                if(j-1>=0)b=grid[i][j]+curr[j-1];
                curr[j]=min(a,b);
            }
            prev=curr;
        }
        return prev[n-1];
    }
};