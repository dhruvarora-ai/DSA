class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        int index=0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=v[index][1]){
                v[index][1] = max(v[index][1], intervals[i][1]);
                v[index][0] = min(v[index][0], intervals[i][0]);
            }
            else{
                v.push_back({intervals[i][0],intervals[i][1]});
                index++;
            }
        }
        return v;

    }
};