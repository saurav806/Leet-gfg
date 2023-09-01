class Solution {
public:
    int getSum(int a, int b) {
        int ans = a^b;
        int iter = a&b;
        while(iter != 0){
            int temp = ans^(iter<<1);
            iter = ans & (iter<<1);
            ans = temp;
        }
        return ans;
    }
};