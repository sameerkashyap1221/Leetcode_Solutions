class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int x=nums[0],n=nums[nums.size()-1];   
        vector<int> mn(nums.size());
        vector<int> mx(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>x){
                x=nums[i];
            }
            mx[i]=x;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<n){
                n=nums[i];
            }
            mn[i]=n;
        }
        for(int i=0;i<nums.size();i++){
            if(mx[i]-mn[i]<=k){
                return i;
            }
        }
        return -1;
    }
};