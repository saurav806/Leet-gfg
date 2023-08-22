class Solution {
public:
    string convertToTitle(int c) {

        string s = "";
        while(c>0){
            c = c - 1;
            char ch = 'A' + c % 26;
            s += ch;
            c /= 26;
        }
        reverse(s.begin(),s.end());
        return s;
        // string  ans = "";
        // while(columnNumber>0 ){
        //     string temp = "";
        //     int rem = columnNumber % 26;
            
        //     columnNumber /= 26;
        //     cout<<columnNumber<<endl;
        //     temp = 'A'+rem-1;
        //     temp += ans;
        //     ans = temp;
        // }
        // return ans;
    }
};