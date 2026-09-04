class Solution {
public:
    double p(double x,long long n){
        if(n==0) return 1;
        double a=p(x,n/2);
        if(n%2==0) return a*a;
        return a*a*x;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            return p(1/x,-N);
        }
        return p(x,N);
    }
};