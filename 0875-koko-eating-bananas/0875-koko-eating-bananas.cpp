class Solution {
public:
    long long hrs(vector<int>& piles, int speed){
        long long hrs = 0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]%speed==0){
                hrs+= piles[i]/speed;
            }
            else{
                hrs+= piles[i]/speed+1;
            }
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(),piles.end());
        long long ans=0;
        while(low<=high){
            long long mid = (low+high)/2;
            long long hours = hrs(piles,mid);
            if(hours<=h){
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