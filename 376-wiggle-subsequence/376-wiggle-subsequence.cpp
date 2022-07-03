class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        int n = size(nums), len = 1, prevDiff = 0, currDiff;
        for(int i = 1; i < n; i++){
            currDiff = nums[i] - nums[i - 1];
            if((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0))
            {
                len++, prevDiff = currDiff;
            }
        }
	   return len;   
    }       
};