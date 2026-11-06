class Solution {
public:
    bool check(vector<int>& weights, int days, long long capacity){
        int current_weights = weights[0];
        int day= 1;
        for(int i=1; i<weights.size(); i++){
            if(current_weights + weights[i]>capacity){
                day++;
                current_weights = weights[i];
            }
            else{
                current_weights+= weights[i];
            }
        }
        if(day<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        long long high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low<=high){
            long long mid = (low+high)/2;
            bool possible = check(weights, days, mid);
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