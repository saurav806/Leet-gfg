class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sub = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            sub+=s[i];
            int k = sub.size();
            string temp = sub;
            // cout<<
            // cout<<n<<" "<<k<<endl;
            if(n%k==0) {
                for(int j=0;j<n/k;j++){
                    temp += sub;
                    if(temp == s) return true;
                    // cout<<j<<endl;
                }
            }
            // cout<<temp<<endl;
            // if(temp == s) return true;
        }
        return false;
    }
};