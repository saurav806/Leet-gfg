class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                    count++;
                else
                    break;
            }
            pq.push({count,i});
        }
        vector<int>ans;
        while(k-- >0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

};