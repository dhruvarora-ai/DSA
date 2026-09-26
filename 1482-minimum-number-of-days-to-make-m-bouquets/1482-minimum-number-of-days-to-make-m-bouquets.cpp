class Solution {
public:
    bool check(vector<int>&bloomDay, int m, int k, int mid){
        int flowers=0;
        int boqt = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                flowers++;
            }
            else{
                flowers=0;
            }
            if(flowers==k){
                boqt++;
                flowers=0;
            }
            if(boqt==m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL *m *k >bloomDay.size()){
            return -1;
        }
        int low = 0;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = check(bloomDay,m,k,mid);
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