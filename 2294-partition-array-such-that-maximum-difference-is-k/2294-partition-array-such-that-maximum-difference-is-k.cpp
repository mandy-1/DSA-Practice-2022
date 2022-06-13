class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans=0,idx=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]-nums[idx]>k)ans++,idx=i;
        }
        return ans+1;        
    }
};