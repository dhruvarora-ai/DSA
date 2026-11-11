class Solution {
public:
    bool check(vector<int>& candies, long long k, int mid){
        long long cnt = 0;
        for(int i=0; i<candies.size(); i++){
            cnt+= candies[i]/mid;
        }
        if(cnt>=k){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(),0LL);
        if(k>sum){
            return 0;
        }
        int low = 1;
        long long high = *max_element(candies.begin(),candies.end());
        int ans = low;
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = check(candies, k,mid);
            if(possible){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};