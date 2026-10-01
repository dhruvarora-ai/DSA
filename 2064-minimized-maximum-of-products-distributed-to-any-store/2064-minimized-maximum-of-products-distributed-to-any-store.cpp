class Solution {
public:
    bool check(vector<int>& quantities, int n, int max_products){
        int shops = 0;
        for(int i=0; i<quantities.size(); i++){
            if(quantities[i]%max_products==0){
                shops+= quantities[i]/max_products;
            }
            else{
                shops+= quantities[i]/max_products +1;
            }
        }
        if(shops<=n){
            return true;
        }
        else{
            return false;
        }
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
       int low = 1;
       int high = *max_element(quantities.begin(),quantities.end());
       int ans=low;
       while(low<=high){
        int mid = (low+high)/2;
        bool possible = check(quantities,n,mid);
        if(possible){
            ans=mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return ans; 
    }
};