class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max= *max_element(candies.begin(), candies.end());
        vector<bool>ans;
        for(int it:candies){
            if(it+extraCandies >= max) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};