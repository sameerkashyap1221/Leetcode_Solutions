class Solution {
public:
    void sol(vector<int>& nums,vector<int>& a,int i,vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(a);
            return;
        }
        a.push_back(nums[i]);
        sol(nums,a,i+1,ans);
        a.pop_back();
        sol(nums,a,i+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        sol(nums,a,0,ans);
        return ans;
    }
};