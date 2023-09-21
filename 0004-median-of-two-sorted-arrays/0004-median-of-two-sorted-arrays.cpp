class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        if(a2.size()<a1.size())
            return findMedianSortedArrays(a2,a1);
        
        int n1 = a1.size(), n2 = a2.size();
        int begin1 = 0, end1 = n1;
        
        while(begin1<=end1){
            
            int i1= (begin1+end1)/2;
            int i2= (n1+n2+1)/2 - i1;
            
            int min1= (i1==n1)?INT_MAX:a1[i1];
            int max1= (i1==0)?INT_MIN:a1[i1-1];
            
            int min2= (i2==n2)?INT_MAX:a2[i2];
            int max2= (i2==0)?INT_MIN:a2[i2-1];
            
            if( max1 <= min2  &&  max2 <= min1 ){
                
                if( (n1+n2) % 2 == 0 )
                    return (double) (max( max1, max2 ) + min( min1, min2 ))/2.0;
                else
                    return (double) max( max1, max2);
            }
            
            else if( max1 > min2)
                end1=i1-1;
            else
                begin1=i1+1;
        }
        return 0;
    }
};