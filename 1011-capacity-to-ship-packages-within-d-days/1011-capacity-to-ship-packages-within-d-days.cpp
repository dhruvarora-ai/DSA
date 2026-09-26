class Solution {
public:
    bool check(vector<int>& weights,int max_days, int capacity){
        int days = 1;
        int current = 0;
        for(int i=0; i<weights.size(); i++){
            if(current + weights[i]>capacity){
                days++;
                current=weights[i];
            }
            else{
                current+= weights[i];
            }
            if(days>max_days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = check(weights, days,mid);
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