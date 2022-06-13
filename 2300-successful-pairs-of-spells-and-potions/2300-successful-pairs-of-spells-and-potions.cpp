class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m=potions.size();
        
       
        vector<int>ans;
        for(int i=0;i<spells.size();i++){
            int curr=spells[i];
            int l=0,r=m-1;
             int res=m;
            while(r>=l){
                int mid=(l+r)/2;
                if(1LL*curr*potions[mid] >=success){
                    res=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            
            ans.push_back(m-res);
        }
        return ans;
    }
};