class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        if(m==1 && n==1 && flowerbed[0]==0) return true;
        for(int i=0;i<m && n>0;i++){
            if(flowerbed[i]==0){
                if(i==0 && flowerbed[i+1] == 0){
                    n--;
                    flowerbed[i]=1;
                }
                else if(i==m-1 && flowerbed[i-1]==0)n--;
                else if(i<m-2 && flowerbed[i+1]==0 && flowerbed[i-1]==0){
                    n--;
                    flowerbed[i]=1;
                }
            }
            // else if(i<m-3) i++;
        }
        if(n == 0) return true;
        return false;
    }
};