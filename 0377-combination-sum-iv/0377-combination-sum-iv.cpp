class Solution {
public:
    // int sum(vector<int>&nums, int target, int i, int &sum){
    //     if(nums.size() == i) return 0;
    //     int ans = 0;
    //     int take = sum(nums, target, i+1, sum+[nums[i]]);
    //     int nTake = sum(nums, target, i+1, sum);
    //     if(sum == target) ans++;
    //     return take+nTake;
    // }
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long>dp(target+1,0);
        dp[0]=1;
        for(int sum = 1; sum<=target ; sum++){
            for(int j = 0; j<nums.size() ; j++){
                int num = nums[j];
                if(sum - num >= 0){
                    dp[sum] += dp[sum - num];
                }
            }
        }
        return dp[target];
    }
};