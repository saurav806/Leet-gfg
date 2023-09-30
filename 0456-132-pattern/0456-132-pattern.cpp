class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>>st;
        int curMin = nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i]>= st.top().first)
                st.pop();
            if(!st.empty() && nums[i] > st.top().second)
                return true;
            st.push({nums[i],curMin});
            curMin = min(curMin, nums[i]);
        }
        return false;
        // int left=nums[0];
        // int n=nums.size();
        // for(int i=1;i<n;i++){
        //     if(left>nums[i]){
        //         left=nums[i];
        //         continue;
        //     }
        //     while(left < nums[i] && i<n-1){
        //         if(nums[i]>nums[i+1] && nums[i+1]>left) return true;
        //         i++;
        //     }
        //     left=nums[i];
        // }
        // return false;
    }
};