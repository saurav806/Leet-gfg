class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> list;
        map<int,vector<int>> group;
        for(int i=0;i<groupSizes.size();i++){
            group[groupSizes[i]].push_back(i);
        }
        for(auto it=group.begin();it!=group.end();it++){
            int cnt=(it->second.size()/it->first);
            int k=0;
            while(cnt){
                vector<int> temp(it->first);
                for(int i=0;i<(it->first);i++){
                    temp[i]=it->second[k];
                    k++;
                }
                cnt--;
                list.push_back(temp);
            }
        }
            
        return list;
    }
};