class Solution {
public:
void all_combo_sum(int sum, vector<int>& nums, int index, int limit, int elment_num, vector<vector<int>> &combo_sum)
{   
    if(index == limit)
    {
        combo_sum[elment_num].push_back(sum);
        return;
    }
    all_combo_sum(sum, nums, index + 1, limit, elment_num, combo_sum); // send without this element.
    sum = sum + nums[index];
    all_combo_sum(sum, nums, index + 1, limit, elment_num + 1, combo_sum); // send including this element
}

int minimumDifference(vector<int>& nums) 
{
    int len = nums.size();
    int total_sum = 0;
    int min = 0;    
    int i;
    for(i=0;i<len;i++)
    {
        total_sum = total_sum + nums[i];
        if(nums[i] < 0)
            min = min + nums[i] * -1;
        else
            min = min + nums[i];
    }
    vector<vector<int>> combo_sum_A (len, vector<int>(0, 0));
    vector<vector<int>> combo_sum_B (len, vector<int>(0, 0));
    all_combo_sum(0, nums, 0, len/2, 0, combo_sum_A);
    all_combo_sum(0, nums, len/2, len, 0, combo_sum_B);

    for(i=0;i<combo_sum_A.size();i++)
    {
        int A_len = combo_sum_A[i].size();
        int mid = len/2;
        if (A_len > 0)
            sort(combo_sum_B[mid - i].begin(), combo_sum_B[mid - i].end());
        
        int j;
        for(j=0;j<A_len;j++)
        {
            int A = combo_sum_A[i][j];
            int req = (total_sum - 2 * A)/2;
            auto itr = lower_bound(combo_sum_B[mid-i].begin(), combo_sum_B[mid-i].end(), req) ;
            int diff = min;
            int index = combo_sum_B[mid - i].size() - 1;
            
            if(itr != combo_sum_B[mid-i].end())
                index = itr - combo_sum_B[mid-i].begin();
            
            diff = abs(total_sum - 2*(combo_sum_B[mid-i][index] + A));

            if(diff < min)
                min = diff;
        }
    }
    return min;
}
};