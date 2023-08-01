//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int n=A.size();
    	int n2=B.size();
    	if(n!=n2) return -1;
    	int sum=0;
    	
    	int ch[256]={0};
    	for(int i=0;i<n;i++){
    	    ch[A[i]]++;
    	    ch[B[i]]--;
    	}
    	for(int i=0;i<256;i++){
    	    if(ch[i]!=0) return -1;
    	}
    	
    	int i=n-1,j=n-1;
    	int count=0;
    	while( i>=0){
    	    if(A[i]==B[j])
    	        j--;
    	    else
    	        count++;
    	    i--;
    	}
    	return count;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends