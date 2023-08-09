class Solution {
public:
    int mcm(vector<int>arr, int i, int j, vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans= INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = mcm(arr, i, k, dp) + mcm(arr, k+1,j, dp) + (arr[i-1] * arr[j] * arr[k]);
            
            if(temp<ans)
                ans= temp;
        }
        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int N= values.size();
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        
        return mcm(values, 1, N-1,dp);
    }
};