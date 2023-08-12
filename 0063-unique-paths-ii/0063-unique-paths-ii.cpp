class Solution {
public:
    // int rec(int i, int j, vector<vector<int>>& Grid, vector<vector<int>>&dp){
    //     if(i<0 || j<0 || Grid[i][j]==1) return 0;
    //     if(i==0 && j==0) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int left=0;
    //     int up =0;
    //      up = rec(i-1,j,Grid,dp);
    //      left = rec(i,j-1,Grid,dp);
    //     return dp[i][j] = up+left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n=Grid.size();
        int m=Grid[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=0,left=0;
                if(i==0 && j==0 && Grid[i][j]==0) {
                    dp[i][j] = 1;
                }
                else if(Grid[i][j]==0){
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};