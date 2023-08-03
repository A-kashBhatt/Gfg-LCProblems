class Solution {
void rowWise(vector<vector<int>> &grid){
    int row=grid.size(),col=grid[0].size();
    for(int i=0;i<row;i++){
        if(grid[i][0])continue;
        for(int j=0;j<col;j++){
            grid[i][j]=!grid[i][j];
        }
    }
}
void colWise(vector<vector<int>> &grid){
    int row=grid.size(),col=grid[0].size();
    for(int i=0;i<col;i++){
        int cnt0=0,cnt1=0;
        for(int j=0;j<row;j++){
            if(grid[j][i])cnt1++;
            else cnt0++;
        }
        if(cnt0>cnt1){
            for(int j=0;j<row;j++)
            grid[j][i]=!grid[j][i];
        }
    }
}
int Calculate(vector<int>v){
    int x=1;
    int ans=0;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i])ans+=x;
        x=x<<1;
    }
    return ans;
}
public:

int matrixScore(vector<vector<int>> grid) {
    int m=grid.size(),n=grid[0].size();
    rowWise(grid);
    colWise(grid);
    int maxScore=0;
    for(int i=0;i<m;i++){
        maxScore+=(Calculate(grid[i]));
    }
    return maxScore;
    
}
};