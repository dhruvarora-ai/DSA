class Solution {
public:
    bool check(vector<int>& time, long long max_time, int totalTrips){
        long long cnt_trips = 0;
        for(int i=0; i<time.size(); i++){
            cnt_trips+= max_time/time[i];
        }
        if(cnt_trips>=totalTrips){
            return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high =(long long)(*min_element(time.begin(),time.end())) * totalTrips;
        long long ans = high;
        while(low<=high){
            long long mid = (low+high)/2;
            bool possible = check(time, mid, totalTrips);
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