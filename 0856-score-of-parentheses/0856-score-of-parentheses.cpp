class Solution {
public:
   int sol(string s,int i,int c,int ans){
    if(i==s.size()) return ans;
    if(s[i]=='('){
        c++;
    }
    else{
        if(s[i-1]=='('){
            ans+=pow(2,c-1);
        }
        c--;
   }
    return sol(s,i+1,c,ans);
   }
    int scoreOfParentheses(string s) {
        return sol(s,0,0,0);
    }
};