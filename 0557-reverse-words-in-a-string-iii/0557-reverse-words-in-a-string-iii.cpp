class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        string temp = "";
        for(int i=0;i<s.size();i++){
            int end=i-1;
            if(i==s.size()-1){
                temp+=s[i];
                end=i;
            }
            if(i==s.size()-1 || s[i] == ' '){
                while(start<end){
                    char ch = temp[start];
                    temp[start] = temp[end];
                    temp[end] = ch;
                    start++;
                    end--;
                }
                start=i+1;
                if(i!=s.size()-1) 
                    temp+=" ";
            }
            else
            temp+=s[i];
        }
        return temp;
    }
};