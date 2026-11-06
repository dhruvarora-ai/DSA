class Solution {
public:
    bool check(vector<int>&bloomDay, int m, int k, int mid){
        int day=0;
        int boqs = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                day++;
            }
            else{
                day=0;
            }
            if(day==k){
                boqs++;
                day=0;
            }
        }
        if(boqs>=m){
            return true;
        }
        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int low = *min_element(bloomDay.begin(), bloomDay.end());
       int high = *max_element(bloomDay.begin(),bloomDay.end());
       int ans = high;
       if(bloomDay.size()< 1LL*m*k){
        return -1;
       }
       while(low<=high){
        int mid = (low+high)/2;
        bool possible = check(bloomDay,m,k,mid);
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