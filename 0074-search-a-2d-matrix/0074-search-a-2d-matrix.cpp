class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0;
        int end=col-1;
        while(start<row && end>=0){
            cout<<start<<" "<<end<<endl;
            int val = matrix[start][end]; 
            if(val == target) return true;
            if(val > target) end--;
            else start ++;
        }
        return false;
    }
};