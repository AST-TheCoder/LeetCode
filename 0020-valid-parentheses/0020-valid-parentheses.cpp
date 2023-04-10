class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') c.push(s[i]);
            else if(c.empty() || (c.top()!=s[i]-1 && c.top()!=s[i]-2)) return 0;
            else c.pop();
        }
        if(c.empty()) return 1;
        else return 0;
    }
};