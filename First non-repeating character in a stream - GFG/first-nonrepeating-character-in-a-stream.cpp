//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Link:- https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int>m;
		    queue<char>q;
		    string ans="";
		    for(int i=0;i<A.size();i++){
		        m[A[i]]++;
		        q.push(A[i]);
		        while(!q.empty()){
		            if(m[q.front()]>1)
		                q.pop();
		            else{
		                ans+=q.front();
		                break;
		            }
		        }
		        if(q.empty())
		            ans+="#";
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends