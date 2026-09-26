class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int n=tasks.size();
        for(auto x:tasks){
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp){
            int a=x.second;
            if(a==1) return -1;
            if(a%3==0){
                ans+=a/3;
            }
            else if(a%3==1){
                ans+=(a-4)/3;
                ans+=2;
            }
            else{
                ans+=(a-2)/3;
                ans+=1;
            }
        }
        return ans;
    }
};