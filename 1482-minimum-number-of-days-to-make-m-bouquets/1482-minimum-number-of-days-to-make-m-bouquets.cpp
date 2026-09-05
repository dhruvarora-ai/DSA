class Solution {
public:
    bool bloom(vector<int>&bloomDay, int m, int k, int mid){
        int flowers = 0;
        int bouquets = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                flowers++;
            }
            else{
                flowers=0;
            }
            if(flowers==k){
                bouquets++;
                flowers=0;
            }

            if(bouquets==m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL* m*k> bloomDay.size()){
            return -1;
        }
        int low=1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;
            bool possible = bloom(bloomDay, m, k, mid);
            if(possible){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};