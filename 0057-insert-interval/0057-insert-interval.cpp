class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if(intervals.empty()){
        return {newInterval};
    }
    bool inserted = false;
    vector<vector<int>>v;
    for(int i=0; i<intervals.size(); i++){
        if(intervals[i][0]>=newInterval[0]){
            intervals.insert(intervals.begin()+i, newInterval);
            inserted=true;
            break;
        }
    }
    if(!inserted){
        intervals.push_back(newInterval);
    }
    int index=0;
    v.push_back({intervals[index][0], intervals[index][1]});
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0]<=v[index][1]){
            v[index][1] = max(intervals[i][1], v[index][1]);
            v[index][0] = min(intervals[i][0], v[index][0]);
        }
        else{
            v.push_back({intervals[i][0], intervals[i][1]});
            index++;
        }
    }
    return v;
    }
};