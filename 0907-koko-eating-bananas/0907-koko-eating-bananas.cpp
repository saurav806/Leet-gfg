class Solution {
public:
    int findMax(vector<int>& piles){
        int ans=piles[0];
        for(int i=1;i<piles.size();i++){
            ans=max(ans,piles[i]);
        }
        return ans;
    }
    int count(vector<int>& piles, int s){
        int total = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%s == 0)
                total += piles[i]/s;
            else
                total += 1+ (piles[i]/s);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
            int max = findMax(piles);
            int min = 1;
            while(min<max){
                int mid = min + (max-min)/2;
                int c = count(piles, mid);
                if(c<=h)
                    max = mid ;
                else
                    min = mid + 1;
            }
            return min;
    }
};