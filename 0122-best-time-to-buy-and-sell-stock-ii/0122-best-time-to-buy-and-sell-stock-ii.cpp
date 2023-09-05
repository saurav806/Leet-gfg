class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         int buy=0;
        int profit=0;
        for(int sell=1;sell<n;sell++){
            if(prices[sell-1]>prices[sell] ||( prices[sell]<=prices[buy] && buy<sell)){
                profit+=(prices[sell-1]-prices[buy]);
                buy=sell;
                continue;
            }
            if(sell==n-1)
                profit+=(prices[sell]-prices[buy]);
            
            
        }
        return profit;
    }
};