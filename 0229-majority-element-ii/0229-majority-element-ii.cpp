class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n<3) {
            if(n==1) return nums;
            if(nums[0] == nums[1]) return {nums[0]};
            else return nums;
        }
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]] == n/3 && mp[nums[i]] != (n/3)+1){
                ans.push_back(nums[i]);
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};