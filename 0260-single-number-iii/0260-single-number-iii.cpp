class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        int XOR = nums[0];
        for(int i=1;i<nums.size();i++){
            XOR = XOR ^ nums[i];
        }
        // int rsb = XOR & ~(XOR-2);
        int cnt = 0;
        while(XOR){
            if(XOR & 1) break;
            cnt++;
            XOR >>= 1;
        }
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & (1 << cnt))
                x ^= nums[i];
            else
                y ^= nums[i];
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};