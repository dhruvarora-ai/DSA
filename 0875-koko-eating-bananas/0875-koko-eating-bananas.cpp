class Solution {
public:
    bool check(vector<int>& piles, int h, int speed){
        int hrs = 0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]<speed){
                hrs+=1;
            }
            else if(piles[i]%speed==0){
                hrs+= piles[i]/speed;
            }
            else{
                hrs+= piles[i]/speed + 1;
            }
            if(hrs>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int low=1;
      int high = *max_element(piles.begin(),piles.end());
      int speed=0;
      while(low<=high){
        int mid = (low+high)/2;
        bool possible = check(piles, h,mid);
        if(possible){
            speed=mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
      }
      return speed;  
    }
};