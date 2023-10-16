class Solution {
public:

    int findCoin(vector<int>&coins, int n, int amount){
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(j==0) dp[i][j]=0;
                else dp[i][j] = INT_MAX -1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1+ dp[i][j-coins[i-1]], 0+ dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int  n = coins.size();
        int res = findCoin(coins, n, amount);
        if(res == INT_MAX-1) res = -1;
        return res;
    }
};