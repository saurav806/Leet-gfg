class Solution {
public:
    int time(int buy, int i, vector<int>& prices,int n, vector<vector<int>>&dp){
        if(i==n) return 0;

        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            profit = max(-prices[i] + time(0,i+1,prices,n,dp), time(1,i+1,prices,n,dp));
        }
        else{
            profit = max(prices[i] + time(1,i+1,prices,n,dp), time(0,i+1,prices,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return time(1,0,prices,n,dp);
    }
};