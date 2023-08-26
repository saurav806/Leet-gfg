class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int pro=1;
        int fcount=0;
        bool fzero=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                fzero=true;
                fcount++;
            }
            else{
                pro*=nums[i];
            }
        }

        for(int i=0;i<nums.size();i++){
            if(fzero){
                if(fcount>1) ans.push_back(0);
                else if(nums[i]!=0)ans.push_back(0);
                else ans.push_back(pro);
            }
            else{
                ans.push_back(pro/nums[i]);
            }
        }
        return ans;
    }
};