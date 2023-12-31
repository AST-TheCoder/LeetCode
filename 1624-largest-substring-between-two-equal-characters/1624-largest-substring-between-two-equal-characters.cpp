class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int c[26], ans=-1;
        memset(c,0,sizeof(c));
        for(int i=s.size()-1;i>=0;i--){
            if(!c[s[i]-'a']) c[s[i]-'a'] = i;
            else ans = max(ans,c[s[i]-'a']-i-1);
        }
        return ans;
    }
};