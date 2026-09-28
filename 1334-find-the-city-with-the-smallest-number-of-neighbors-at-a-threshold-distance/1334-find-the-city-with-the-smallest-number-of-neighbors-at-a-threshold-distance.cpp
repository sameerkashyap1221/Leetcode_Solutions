class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> a(n,vector<int>(n,INT_MAX));
        for(auto it: edges){
            a[it[0]][it[1]]=it[2];
            a[it[1]][it[0]]=it[2];
        }
        int ans=0;
        for(int v=0;v<n;v++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[i][v]!=INT_MAX && a[v][j]!=INT_MAX){
                            a[i][j]=min(a[i][j],a[i][v] + a[v][j]);
                    }
                }
            }
        }
        int min_cost=INT_MAX;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(a[i][j]<=distanceThreshold){
                    c++;
                }
            }
            if(min_cost>=c){
                min_cost=c;
                ans=i;
            }
        }
        return ans;
    }
};