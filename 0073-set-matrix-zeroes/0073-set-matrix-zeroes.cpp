class Solution {
public:
    void fillRow(int row,vector<vector<int> > &matrix){
        int c=matrix[0].size();
        for(int i=0;i<c;i++)
            matrix[row][i]=0;
    }
    void fillCol(int col,vector<vector<int> > &matrix){
        int r=matrix.size();
        for(int i=0;i<r;i++)
            matrix[i][col]=0;
    }
    void setZeroes(vector<vector<int>>& matrix)
    {
        // code here
        int r=matrix.size();
        int c=matrix[0].size();
        queue<pair<int,int>>posX;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0)
                posX.push({i,j});
            }
        }
        
        while(!posX.empty()){
            int row = posX.front().first;
            int col = posX.front().second;
            fillRow(row,matrix);
            fillCol(col,matrix);
            posX.pop();
        }
    }
};