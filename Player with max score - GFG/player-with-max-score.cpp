//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int win(int arr[], int l, int r,vector<vector<int>>&mem){
        if(l>r) return 0;
        if(mem[l][r]!=-1) return mem[l][r];
        int left= arr[l] - win(arr, l+1, r,mem);
        int right = arr[r] - win(arr,l,r-1,mem);
        
        return mem[l][r]=max(left,right);
    }
    bool is1winner(int N,int arr[]) {
        
        // code here
        vector<vector<int>>mem(N,vector<int>(N,-1));
        int ans= win(arr,0,N-1,mem);
        return  ans>=0;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends