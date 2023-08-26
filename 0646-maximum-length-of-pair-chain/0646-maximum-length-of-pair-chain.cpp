class Solution {
public:
    static bool comp(vector<int>a, vector<int>b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int count=1;
        int start=0;
        for(int i=1;i<pairs.size();i++){
            if(pairs[start][1]<pairs[i][0]){
                start=i;
                count++;
            }
        }
        return count;
    }
};