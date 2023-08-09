class Solution {
public:
    int minDistance(string str1, string str2) {
        int m=str1.size();
	    int n=str2.size();
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++) dp[i][0] = 0;
	    for(int i=0;i<=n;i++) dp[0][i] = 0;
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            if(str1[i-1] == str2[j-1])
	                dp[i][j] = 1+ dp[i-1][j-1];
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    return (m+n - 2*dp[m][n]);
    }
};