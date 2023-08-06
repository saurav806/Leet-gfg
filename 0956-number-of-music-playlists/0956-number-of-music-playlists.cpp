class Solution {
public:
    #define ll long long
    const int mod = 1e9 + 7;
    ll solve(int n, int goal, int k, vector<vector<int>>&dp){
        if(n==0 && goal==0) return 1;
        if(n==0 || goal==0) return 0;
        if(dp[n][goal] != -1) return dp[n][goal];
        ll pick = n*(solve(n-1, goal-1, k, dp));
        ll npick = max(n-k,0)*(solve(n,goal-1,k,dp));
        return dp[n][goal] = (pick + npick)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return solve(n, goal, k, dp);
    }
};