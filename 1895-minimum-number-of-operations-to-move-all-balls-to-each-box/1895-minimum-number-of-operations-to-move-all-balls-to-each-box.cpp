class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> arr;
        
        for(int i=0;i<boxes.length();i++){
            // cout<<boxes[i]<<endl;
            int count=0;
            // if(boxes[i]=='0'){
                for(int j=0;j<boxes.length();j++){
                    if(boxes[j]=='1'){
                        count+=abs(j-i);
                    }
                }

            // }
            // else{
            //     for(int j=0;j<boxes.length();j++){
            //         if(boxes[j]=='1'){
            //             count+=abs(j-i);
            //         }
            //     }
            // }
            arr.push_back(count);
        }
        //cout<<i;
        return arr;
    }
};