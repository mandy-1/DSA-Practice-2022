class Solution {
public:
    int maxProfit(vector<int>& a) {
        int maxi=0;
        int least= a[0];
        for(int i=1;i<a.size();i++){
            int cur=a[i]-least;
            maxi=max(cur,maxi);
            least=min(least,a[i]);
        }
        return maxi;
    }
};