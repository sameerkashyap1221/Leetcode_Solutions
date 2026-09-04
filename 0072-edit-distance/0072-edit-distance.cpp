class Solution {
public:
    int sol(string word1,string word2,int i,int j,vector<vector<int>>& dp){
        int n=word1.size(),m=word2.size();
        if(i>=n) return m-j;
        if(j>=m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(word1[i]==word2[j]){
            dp[i][j]=ans=sol(word1,word2,i+1,j+1,dp);
        }
        else{
            int insert=1+sol(word1,word2,i,j+1,dp);
            int del=1+sol(word1,word2,i+1,j,dp);
            int rep=1+sol(word1,word2,i+1,j+1,dp);
            dp[i][j]=ans=min({ans,insert,del,rep});
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return sol(word1,word2,0,0,dp);
    }
};
