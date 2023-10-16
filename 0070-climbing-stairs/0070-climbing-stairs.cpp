class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int prev = 1;
        int mprev = 1;
        int ans;
        for(int i=2;i<=n;i++){
            ans = prev+mprev;
            mprev = prev;
            prev = ans;
        }
        return ans;
    }
};