//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int partition(int n, int arr[], int sum){
    //     if(sum==0) return true;
    //     if(n==0) return false;
        
    //     if(arr[n-1]<=sum)
    //         return partition(n-1,arr,sum-arr[n-1]) || partition(n-1,arr,sum);
    //     else
    //         return partition(n-1,arr,sum);
    // }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        if(sum%2!=0) return 0;
        int m=sum/2;
        int bag[N+1][m+1];
        for(int i=0;i<=N;i++){
            for(int j=0;j<=m;j++){
                if(i==0) bag[i][j] = 0;
                if(j==0) bag[i][j] = 1;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=m;j++){
                if(arr[i-1] <= j)
                    bag[i][j] = bag[i-1][j-arr[i-1]] || bag[i-1][j];
                else
                    bag[i][j] = bag[i-1][j];
            }
        }
        
        return bag[N][m];
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends