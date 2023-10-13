class Solution {
public:
    // int costly(int n,vector<int>&cost){
    //     if(n==1)
    //         return 1;
    //     int left= costly(n-1,cost) + abs(cost[n-1] - cost[n]);
    //     int right=INT_MAX;
    //     if(n>1)
    //         right= costly(n-2,cost) + abs(cost[n-2] - cost[n]);
    //     return min(left,right);
        
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int>dp(cost.size()+1,-1);
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};