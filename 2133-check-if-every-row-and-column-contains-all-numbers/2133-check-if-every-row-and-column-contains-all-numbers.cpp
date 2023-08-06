class Solution {
    bool isValidRow(int row,vector<vector<int>>& matrix){
        unordered_map<int,int>m;
        int n=matrix.size();
        for(int col=0;col<n;col++){
            if(m.count(matrix[row][col]))return false;
            m[matrix[row][col]]++;
        }
        return true;
    }
    bool isValidCol(int col,vector<vector<int>>& matrix){
        unordered_map<int,int>m;
        int n=matrix.size();
        for(int row=0;row<n;row++){
            if(m.count(matrix[row][col]))return false;
            m[matrix[row][col]]++;
        }
        return true;
    }
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        bool ans=true;
        for(int i=0;i<n;i++){
            ans=ans & isValidRow(i,matrix);
            if(ans==false)return ans;            
            ans=ans & isValidCol(i,matrix);
            if(ans==false)return ans;
        }
        return ans;
    }
};