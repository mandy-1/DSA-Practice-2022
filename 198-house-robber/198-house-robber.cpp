class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int rob=nums[i];
            if(i>1){
                rob+=prev2;
            }
            int notRob=0+prev;
            int cur=max(rob,notRob);
            prev2=prev;
            prev=cur;
        }
        return prev;    
    }
};