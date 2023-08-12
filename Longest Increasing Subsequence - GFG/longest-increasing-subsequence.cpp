//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>lis;
       lis.push_back(a[0]);
       for(int i=1;i<n;i++){
            int val=a[i];
            if(val>lis[lis.size()-1])
                lis.push_back(val);
            else{
                int ind=lower_bound(lis.begin(),lis.end(),val)-lis.begin();
                lis[ind] = val;
            }
       }
       return lis.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends