class Solution {
    bool isValidRow(int row,vector<vector<char>>& board){
        unordered_map<char,int>m;
        for(int col=0;col<9;col++){
            if(board[row][col]=='.')continue;
            if(m.count(board[row][col]))return false;
            m[board[row][col]]++;
        }
        return true;
    }
    bool isValidCol(int col,vector<vector<char>>& board){
        unordered_map<char,int>m;
        for(int row=0;row<9;row++){
            if(board[row][col]=='.')continue;
            if(m.count(board[row][col]))return false;
            m[board[row][col]]++;
        }
        return true;
    }
    bool isValidGrid(int x,int y,vector<vector<char>>& board){
        unordered_map<char,int>m;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[x+i][y+j]=='.')continue;
                if(m.count(board[x+i][y+j]))return false;
                m[board[x+i][y+j]]++;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans=true;
        for(int i=0;i<9;i++){
            ans = ans & isValidRow(i,board);
            ans = ans & isValidCol(i,board);
            if(ans==false)return ans;
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                ans = ans & isValidGrid(i,j,board);
                if(ans==false)return ans;
            }
        }
        return ans;
    }
};