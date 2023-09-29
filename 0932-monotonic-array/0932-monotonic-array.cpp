class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2) return true;
        int dir = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                if(dir == 0) dir = 1;
                else if (dir == -1) return false;
            }
            else if (nums[i] < nums[i-1]) {
                if(dir == 0) dir = -1;
                else if (dir == 1) return false;
            }
        }
        return true;
    }
};