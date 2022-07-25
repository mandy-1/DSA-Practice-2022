class Solution {
    //find the first position of target.....
    int first_pos(int start , int end , vector<int>& nums , int target)
    {
        int result = -1;    // make a variable to stroe the index of first occurance.
        while(start <= end)
        {
            int mid = start + (end - start)/2;  
            if(nums[mid] == target)
            { 
                result = mid;  //if we find the target at mid position then we store the mid in result variable.
                end = mid - 1;  //and continue to find the first occurance in the left of mid and if we find we update the result.
            }
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return result;
    }
    
    //find the last position of target.....
    int last_pos(int start , int end , vector<int>& nums , int target)
    {
        int result = -1;    // make a variable to stroe the index of first occurance.
        while(start <= end) 
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                result = mid;   //if we find the target at mid position then we store the mid in result variable.
                start = mid + 1;    //and continue to find the last occurance in the right of mid and if we find we update the result.
            }
            else if(nums[mid] >= target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return result;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0 , end = n - 1;
        vector<int>ans(2);
        ans[0] = first_pos(start , end , nums , target);
        ans[1] = last_pos(start , end , nums , target);
        return ans;
    }
};