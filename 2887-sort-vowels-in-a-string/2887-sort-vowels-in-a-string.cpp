class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>vowels = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char>v;
        for(int i=0;i<s.size();i++){
                if(vowels.find(s[i])!=vowels.end())
                        v.push_back(s[i]);
        }
        sort(v.begin(),v.end());
        int j=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(vowels.find(s[i])!=vowels.end()){
                ans+=v[j];
                j++;
            }
            else
            ans+=s[i];
        }
        return ans;
    }
};