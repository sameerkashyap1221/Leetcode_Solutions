class Solution {
public:int missingMultiple(vector<int>& nums, int k) {
       int ans=k;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        if(nums[i]==ans){
            ans+=k;
        }
       }
       return ans;
}}  ;  