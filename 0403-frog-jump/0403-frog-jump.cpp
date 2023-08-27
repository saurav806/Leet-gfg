class Solution {
public:
    map<int,int>m;
    int dp[2000][2000];
    int solve(int i,int k, vector<int>&stones){
        if(i==stones.size()-1) return true;

        if(dp[i][k] != -1) return dp[i][k];

        bool k1=false;
        bool k2=false;
        bool k3=false;

        if(m.find(stones[i]+k) != m.end())
            k1 = solve(m[stones[i]+k],k,stones);
        if(k>1 && m.find(stones[i]+k-1) != m.end())
            k2 = solve(m[stones[i]+k-1],k-1,stones);
        if(m.find(stones[i]+k+1) != m.end())
            k3 = solve(m[stones[i]+k+1],k+1,stones);

        dp[i][k] = k1 || k2 || k3;

        return dp[i][k];
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0] >1) return false;
        for(int i=0;i<stones.size();i++){
            m[stones[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        return solve(1,1,stones);
    }
};