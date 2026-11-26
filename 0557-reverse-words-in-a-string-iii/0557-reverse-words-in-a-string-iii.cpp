class Solution {
public:
    void rev(string &s,int p1,int p2){
        while(p1<p2){
            swap(s[p1],s[p2]);
            p1++;
            p2--;
        }
        return;
    }
    string reverseWords(string s) {
        int p1 = 0;
        int p2= p1+1;
        while(p2<s.size()){
            if(p2==s.size()-1){
                rev(s,p1,p2);
            }
            if(s[p2]==' '){
                rev(s,p1,p2-1);
                p1 = p2+1;
            }
            p2++;
        }
        return s;
    }
};