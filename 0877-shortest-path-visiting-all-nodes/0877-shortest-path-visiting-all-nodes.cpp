inline int compress(int mask, int i){
    return mask<<4|i;//shift 4 positons left or i  
}
class Solution {
public:
    using int2 = pair<int, int>;   

    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size(); // n is small <=12
        unordered_set<int> path; //But there are many paths 
        const int allMask = (1<<n)-1;
        
        if (n == 1) return 0;

        queue<int2> q;
        for (int i = 0; i < n; i++) {
            int mask = 1<<i;
            int _mask4_i=compress(mask, i);//i|mask<<4
            q.emplace(0, _mask4_i);
            path.insert(_mask4_i); 
        }

        while (!q.empty()) {
            auto [d, _mask4_i] = q.front();
        //    cout<<"["<<d<<", "<<i<<", "<<mask<<"]\n";
            q.pop();
            int i=0x0F& _mask4_i, mask=_mask4_i>>4;
            if (mask==allMask) return d;
            
            for (int j : graph[i]) {
                int jMask= mask|(1<<j); //mask for each neighbor
                int edge=compress(jMask, j);
                
                if (path.count(edge)==0) {
                    path.insert(edge);
                    q.emplace(d+1, edge);
                }
            }
        }
        return -1;
    }
};