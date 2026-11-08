class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int largest = -1;
      vector<int>v={-1,-1};
      for(int i=0; i<mat.size(); i++){
        for(int j = 0; j<mat[0].size(); j++){
            if(mat[i][j]>largest){
                largest = mat[i][j];
                v[0] = i;
                v[1] = j;
            }
        }
      }  
      return v;
    }
};