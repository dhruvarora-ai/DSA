class Solution {
public:
    bool check(vector<int>& quantities, int n, int max_products){
        int cnt_stores =0;
        for(int i=0; i<quantities.size(); i++){
            if(quantities[i]%max_products==0){
                cnt_stores+= quantities[i]/max_products;
            }
            else{
                cnt_stores+= quantities[i]/max_products + 1;
            }
        }
        if(cnt_stores<=n){
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());
        int ans = high;
        
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = check(quantities,n,mid);
            if(possible){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};