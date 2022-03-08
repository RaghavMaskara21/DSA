class Solution {
public:
    
    bool isValid(char s, int row, int col, vector<vector<char>>& board ){
        for(int i=0;i<board.size();i++){
            if(board[row][i]==s) return false;
        }
        for(int i=0;i<board.size();i++){
            if(board[i][col]==s) return false;
        }
        int x=row/3;
        int y=col/3;
        for(int i=0; i<3 ; i++){
            for(int j=0; j<3;j++){
                if(board[i+(x*3)][j+(y*3)]==s) return false;
            }
        }
        return true;
    }
    
    
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
         for(int j=0;j<9;j++){
             if(board[i][j]=='.'){
                 for(char ch='1';ch<='9';ch++){
                     if(isValid(ch,i,j,board)){
                        board[i][j]=ch;
                        if(solve(board)) return true;
                        else board[i][j]='.';
                    }
                 }
                 return false;
             }
         }
     }
        return true;
    }

    
    void solveSudoku(vector<vector<char>>& board) {
     solve(board);
        
    }
};