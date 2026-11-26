class Solution {
public:
    void rev(string &s, int p1, int p2, int k){
        while(p1<p2){
            swap(s[p1],s[p2]);
            p1++;
            p2--;
        }
        return;
    }
    string reverseStr(string s, int k) {
        for(int i=0; i<s.size(); i = i+ 2*k){
            if(i+2*k-1<s.size()){
                rev(s,i,i+k-1,k);
            }
            else if(i+ 2*k -1 >=s.size() && i+k-1 <s.size()){
                rev(s,i,i+k-1,k);
            }
            else{
                rev(s,i,s.size()-1,k);
            }
        } 
        return s;  
    }
};