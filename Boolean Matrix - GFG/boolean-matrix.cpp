//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void fillRow(int row,vector<vector<int> > &matrix){
        int c=matrix[0].size();
        for(int i=0;i<c;i++)
            matrix[row][i]=1;
    }
    void fillCol(int col,vector<vector<int> > &matrix){
        int r=matrix.size();
        for(int i=0;i<r;i++)
            matrix[i][col]=1;
    }
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here
        int r=matrix.size();
        int c=matrix[0].size();
        queue<pair<int,int>>posX;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1)
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


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends