//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mcm(int arr[], int i, int j, vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans= INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = mcm(arr, i, k, dp) + mcm(arr, k+1,j, dp) + (arr[i-1] * arr[j] * arr[k]);
            
            if(temp<ans)
                ans= temp;
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        int ans= mcm(arr, 1, N-1,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends