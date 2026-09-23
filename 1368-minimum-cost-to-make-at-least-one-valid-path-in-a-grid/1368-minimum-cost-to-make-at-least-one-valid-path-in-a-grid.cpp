class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int dir_X[]={0,0,1,-1};
        int dir_Y[]={1,-1,0,0};
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        dist[0][0]=0;
        while(!dq.empty()){
            int dr=dq.front().first;
            int dc=dq.front().second;
            dq.pop_front();
            for(int i=0;i<4;i++){
                int n_dr=dr + dir_X[i];
                int n_dc=dc + dir_Y[i];
                if(n_dr>=0 and n_dr<n and n_dc>=0 and n_dc<m){
                    int cost;
                    if(grid[dr][dc]==i+1){
                        cost=0;
                    }
                    else{
                        cost=1;
                    }
                    if(dist[dr][dc]+cost<dist[n_dr][n_dc]){
                        dist[n_dr][n_dc]=dist[dr][dc]+cost;
                        if(cost==0){
                            dq.push_front({n_dr,n_dc});
                        }
                        else{
                            dq.push_back({n_dr,n_dc});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};