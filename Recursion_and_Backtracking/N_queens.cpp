class Solution {
public:
    bool isSafe(int row, int col,vector<string> &chess ){
       int i=row;
        int j=col;
        while(i>=0 && j>=0){
           if(chess[i][j]=='Q') return false;
        i--;
        j--;
       } 
    i=row;
    j=col;
        while(i<chess.size() && j>=0){
           if(chess[i][j]=='Q') return false;
            i++;
            j--;
       } 
    
        for( i=0;i<=col; i++){
            if(chess[row][i]=='Q') return false;
        }
        return true;
    }
    
    void solve(int col, vector<vector<string>> &ans, vector<string> &chess){
        if(col==chess.size()){
            ans.push_back(chess);
            return;
        }
        for(int i=0;i<chess.size();i++){            
            if(isSafe(i,col,chess)){
                chess[i][col]='Q';
                solve(col+1,ans,chess);
                chess[i][col]='.';
            }            
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> chess(n);
       string s(n, '.');
        for(int i=0;i<n;i++){
        chess[i]=s;    
        }
        solve(0,ans,chess);
        return ans;
    }
};