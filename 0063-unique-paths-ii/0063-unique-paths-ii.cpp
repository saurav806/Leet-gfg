class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& Grid, vector<vector<int>>&dp){
        if(i<0 || j<0 || Grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        int left=0;
        int up =0;
         up = rec(i-1,j,Grid,dp);
         left = rec(i,j-1,Grid,dp);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n=Grid.size();
        int m=Grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return rec(n-1,m-1,Grid,dp);
    }
};