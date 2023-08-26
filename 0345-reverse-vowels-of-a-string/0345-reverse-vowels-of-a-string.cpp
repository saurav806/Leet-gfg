class Solution {
public:
    unordered_set<char>vowel = {'A','E','I','O','U','a','e','i','o','u'};
    string reverseVowels(string s) {
        vector<char>nVowel ;
        for(int i=0;i<s.size();i++){
            if(vowel.find(s[i])!=vowel.end()){
                nVowel.push_back(s[i]);
            }
        }
        
        string ans="";
        int j=nVowel.size()-1;
        for(int i=0;i<s.size();i++){
            if(vowel.find(s[i])!=vowel.end()){
                ans+=nVowel[j--];
            }
            else ans+=s[i];
        }
        return ans;
    }
};