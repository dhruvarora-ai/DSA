class Solution {
public:
    bool check(vector<int>& dist, int speed,double hours){
        double cnt_hrs =0;
        for(int i=0; i<dist.size(); i++){
            if(dist[i]%speed==0){
                cnt_hrs+= (double)dist[i]/speed;
            }
            else{
                if(i==dist.size()-1){
                    cnt_hrs+= (double)dist[i]/speed;
                }
                else{
                    cnt_hrs+= ceil((double)dist[i]/speed);
                }
            }
        }
        if(cnt_hrs<=hours){
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size()>ceil(hour)){
            return -1;
        }
        int low = 1;
        int high = 10000000;
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = check(dist, mid,hour);
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