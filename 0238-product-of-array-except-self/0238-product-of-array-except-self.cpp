class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] *= right;
            right *= nums[i];
        }
        // int pro=1;
        // int fcount=0;
        // bool fzero=false;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         fzero=true;
        //         fcount++;
        //     }
        //     else{
        //         pro*=nums[i];
        //     }
        // }

        // for(int i=0;i<nums.size();i++){
        //     if(fzero){
        //         if(fcount>1) ans.push_back(0);
        //         else if(nums[i]!=0)ans.push_back(0);
        //         else ans.push_back(pro);
        //     }
        //     else{
        //         ans.push_back(pro/nums[i]);
        //     }
        // }
        return ans;
    }
};