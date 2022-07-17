class Solution {
public:
    bool check(string& s1,string& s2){
        if(s1.size() != s2.size()+1)return false;
        int first=0,second=0;
        while(first<s1.size()){
            if(s1[first] == s2[second] && second<s2.size()){
                first++,second++;
            }
            else{
                first++;
            }
        }
        if(second == s2.size() && first == s1.size())return true;
        return false;
    }
    
   static bool comp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int>dp(n,1);
        sort(words.begin(),words.end(),comp);
        int maxi=0;
        for(int i=0;i<n;i++){
            cout<<words[i]<<" ";
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};