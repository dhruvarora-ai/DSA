class Solution {
public:
    int mySqrt(int x) {
        if(x<=1){
            return x;
        }
       int low = 1;
       int high = x/2;
       int ans = -1;
       while(low<=high){
        int mid  = (low+high)/2;
        if(1LL*mid*mid == x){
            ans = mid;
            break;
        }
        else if(1LL*mid*mid>x){
            high = mid-1;
        }
        else{
            ans = mid;
            low = mid+1;
        }
       }
       return ans;
    }
};