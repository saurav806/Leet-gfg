class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        unordered_map<int,int>m2;
        vector<vector<int>>ans;
        for(auto it:nums1) 
        m[it]++;
        for(auto it:nums2) 
        m2[it]++;
        set<int>ans1;
        set<int>ans2;
        for(int i=0;i<nums1.size();i++)
        {
            if(m2.find(nums1[i])==m2.end() )
                ans1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i])==m.end())
                ans2.insert(nums2[i]);
        }
        vector<int>a,b;
        for(auto it:ans1) a.push_back(it);
        for(auto it:ans2) b.push_back(it);
        
        return {a,b};
    }
};