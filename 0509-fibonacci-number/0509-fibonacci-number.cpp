class Solution {
public:
    int fib(int n) {
        int p=1,p2=0;
        int ans=0;
        if(n<=1) return n;
        for(int i=2;i<n+1;i++){
            ans=p+p2;
            p2=p;
            p=ans;
        }
        return ans;
    }
};