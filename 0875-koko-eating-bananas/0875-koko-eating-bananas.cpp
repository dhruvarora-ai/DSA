class Solution {
public:
    bool check(vector<int>& piles, int h, long long speed){
        long long hrs = 0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]%speed==0){
                hrs+= piles[i]/speed;
            }
            else{
                hrs+= piles[i]/speed +1;
            }
        }
        if(hrs<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      long long low = 1;
      long long high = *max_element(piles.begin(),piles.end());
      int ans = high;
      while(low<=high){
        long long mid  = (low+high)/2;
        bool possible = check(piles, h,mid);
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