class Solution {
public:
    void rev(string &s){
        int p1 = 0;
        int p2 = s.size()-1;
        while(p1<p2){
            swap(s[p1],s[p2]);
            p1++;
            p2--;
        }
        return;
    }
    string finalString(string s) {
        int p=0;
        string s1;
        while(p<s.size()){
            if(s[p]=='i' || s[p]=='I'){
                rev(s1);
            }
            else{
                s1+= s[p];
            }
            p++;
        }
        return s1;
    }
};