class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
     int ans=INT_MAX;
     int mn,mx;
     for(int i=0;i<nums.size();i++){
        mn=*min_element(nums.begin()+i,nums.end());
        mx=*max_element(nums.begin(),nums.begin()+i);
        if(mx-mn<=k && ans>i){
            ans=i;
        }
     }
     return (ans==INT_MAX)?-1:ans;
    }
};