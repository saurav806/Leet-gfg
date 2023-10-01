class Solution {
public:
    string reverseWords(string s) {
        string ans= "";
        int start = 0;
        string temp = "";
        for(int end=0;end<s.size();end++){
            if(s[end] == ' '){
                reverse(temp.begin(), temp.end());
                ans+=temp;
                ans+=" ";
                temp = "";
                continue;
            }
            temp+=s[end];
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};