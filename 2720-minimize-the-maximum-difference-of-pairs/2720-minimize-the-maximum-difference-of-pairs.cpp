class Solution {
private:
    bool isValid(vector<int>& nums, int mid, int p){
        int count=0;
        for(int i=0;i<nums.size()-1 && count<p;){
            if(nums[i+1] - nums[i] <= mid){
                count++;
                i += 2;
            }
            else
                i++;
        }
        return count >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l=0;
        int r= nums.back() - nums.front();
        while(l<r){
            int mid= l+(r-l)/2;
            if( isValid(nums, mid, p))
                r = mid;
            else
                l= mid+1;
        }
        return l;
    }
};