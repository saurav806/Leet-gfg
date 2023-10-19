class Solution {
public:

    int lcs(string &str1, string &str2, int n, int m, vector<vector<int>>&dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(str1[n-1] == str2[m-1])
            return dp[n][m] = 1+ lcs(str1,str2, n-1, m-1, dp);
        else
            return dp[n][m] = max(lcs(str1,str2,n-1,m,dp), lcs(str1,str2,n,m-1,dp));
    }
    int minDistance(string str1, string str2) {
        int n=str1.size();
	    int m=str2.size();
        if(m==n && m==1 && str1!=str2) return 2;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

	    int res = lcs(str1,str2,n,m,dp);
        cout<<res<<endl;
	    return m+n-(2*res);
    }
};