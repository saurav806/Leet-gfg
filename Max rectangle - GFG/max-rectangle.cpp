//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> fnsl(int arr[], int n){
        vector<int>ans;
        stack<int>s;
        
        for(int i=0;i<n;i++){
            if(s.empty()) ans.push_back(-1);
            else if(arr[s.top()] < arr[i]) ans.push_back(s.top());
            else{
                while(!s.empty() && arr[s.top()] >= arr[i])
                    s.pop();
                if(s.empty()) ans.push_back(-1);
                else ans.push_back(s.top());
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> fnsr(int arr[], int n){
        vector<int>ans;
        stack<int>s;
        
        for(int i=n-1;i>=0;i--){
            if(s.empty()) ans.push_back(n);
            else if(arr[s.top()] < arr[i]) ans.push_back(s.top());
            else{
                while(!s.empty() && arr[s.top()] >= arr[i])
                    s.pop();
                if(s.empty()) ans.push_back(n);
                else ans.push_back(s.top());
            }
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int getMaxArea(int arr[], int n)
    {
        // Your code here
        vector<int>nsl;
        vector<int>nsr;
        nsl = fnsl(arr,n);
        nsr = fnsr(arr,n);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int res = (nsr[i]-nsl[i]-1) * arr[i];
            ans = max(ans,res);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int arr[m];
        int maxi = 0;
        int ans=0;
        for(int i=0;i<m;i++){
            arr[i] = M[0][i];
        }
        ans = getMaxArea(arr,m);
        maxi = max(maxi,ans);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] == 0) arr[j] =0;
                else arr[j] += 1;
            }
            ans = getMaxArea(arr,m);
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends