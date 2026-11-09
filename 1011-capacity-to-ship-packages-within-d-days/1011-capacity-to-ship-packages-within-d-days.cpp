class Solution {
public:
    bool check(vector<int>& weights, int days, int max_weights){
        int count_days = 1;
        int current_filled = weights[0];
        for(int i=1; i<weights.size(); i++){
            if(current_filled + weights[i] > max_weights){
                count_days++;
                current_filled = weights[i];
            }
            else{
                current_filled+= weights[i];
            }
        }
        if(count_days>days){
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int  low =     *max_element(weights.begin(), weights.end());
       int high = accumulate(weights.begin(),weights.end(),0);
       int ans = high;
       while(low<=high){
        int mid = (low+high)/2;
        bool possible = check(weights, days, mid);
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