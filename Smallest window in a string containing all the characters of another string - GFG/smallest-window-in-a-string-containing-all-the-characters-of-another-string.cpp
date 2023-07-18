//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.

    string smallestWindow (string str, string t)
    {
        // Your code here
        vector<int>s(26,0);
        if(str == t) return t;

        for(int i=0;i<t.size();i++){
            s[t[i]-'a']++;
        }
        
        vector<int>m(26,0);
        int n=t.size();
        int count=0;
        int start=0;
        int last=0;
        int min_length=1e9;
        int sindex=-1;
        while(last < str.size()){
            m[str[last]-'a']++;
            if(m[str[last]-'a'] <= s[str[last]-'a']) count++;

            if(count==n){
              while(m[str[start]-'a'] > s[str[start]-'a']){
                    m[str[start]-'a']--;
                    start++;
              }
              if(min_length > last-start+1){
                  min_length = last-start+1;
                    sindex = start;
              }
            }
            last++;
        }

        if(sindex == -1) return "-1";
        else return str.substr(sindex, min_length);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends