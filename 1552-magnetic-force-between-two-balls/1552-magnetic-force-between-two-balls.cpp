class Solution {
public:
    bool check(vector<int>& position, int distance, int m){
        int balls = 1;
        int current =0;
        for(int i=1; i<position.size(); i++){
            if(position[i]-position[current] >= distance){
                balls++;
                current =i;
            }
            else{
                continue;
            }
            if(balls==m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position[position.size()-1] - position[0];
        int ans =1;
        while(low<=high){
            int mid=(low+high)/2;
            bool possible = check(position, mid, m);
            if(possible){
                ans = mid;
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};