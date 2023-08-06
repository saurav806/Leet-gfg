class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int N=nums.size();
        for(int i=0;i<N;i++)
            sum+=nums[i];
        if(sum%2!=0) return 0;
        int m=sum/2;
        int bag[N+1][m+1];
        for(int i=0;i<=N;i++){
            for(int j=0;j<=m;j++){
                if(i==0) bag[i][j] = 0;
                if(j==0) bag[i][j] = 1;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=m;j++){
                if(nums[i-1] <= j)
                    bag[i][j] = bag[i-1][j-nums[i-1]] || bag[i-1][j];
                else
                    bag[i][j] = bag[i-1][j];
            }
        }
        
        return bag[N][m];
    }
};