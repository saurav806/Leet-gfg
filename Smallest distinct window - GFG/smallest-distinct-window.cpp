//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_set<char>s;
        for(int i=0;i<str.size();i++){
            s.insert(str[i]);
        }
        unordered_map<char,int>m;
        int n=s.size();
        int count=0;
        int start=0;
        int last=1;
        m[str[start]]++;
        count++;
        int ans=INT_MAX;
        while(start<last && last < str.size()){
            if(count<n){
                if(m[str[last]]==0) count++;
                m[str[last]]++;
                last++;
            }
            else if(count==n){
                ans=min(ans,(last-start));
                if(m[str[start]]==1) count--;
                m[str[start]]--;
                start++;
                
            }
        }
        while(count==n){
                ans=min(ans,(last-start));
                if(m[str[start]]==1) count--;
                m[str[start]]--;
                start++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends