class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int size = nums.size();
        int temp = 1;
        int result = 1;
        if(size == 0)
            return 0;
        else if(size == 1)
            return 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-1;i++)
        {
            if(nums[i+1] == nums[i])
            {
                continue;
            }
            else
            {
                if(nums[i+1] - nums[i] == 1 || nums[i+1] - nums[i] == -1)
                    temp++;
                else
                    temp = 1;
                result = max(result,temp);
            }
        }
        return result; 
    }
};