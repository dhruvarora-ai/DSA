class Solution {
public:
    bool load(vector<int>& weights, int capacity,int max_days){
        int sum = 0;
        int days=1;
        for(int i=0; i<weights.size(); i++){
            if(sum + weights[i]<=capacity){
                sum+= weights[i];
            }
            else{
                sum = weights[i];
                days++;
            }
        }
        if(days<=max_days){
            return true;
        }
        else{
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = low;
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = load(weights, mid, days);
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