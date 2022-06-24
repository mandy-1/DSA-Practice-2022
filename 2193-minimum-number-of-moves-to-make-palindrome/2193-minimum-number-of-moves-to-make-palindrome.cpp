class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l=0,r=s.size()-1,count=0;
        while(l<=r){
            if(s[l] != s[r]){
                int k=r;
                while(k>l && s[l] != s[k]){
                    k--;
                }
                if(l==k){
                    swap(s[l],s[l+1]);
                    count++;
                    l--,r++;
                }
                else{
                    while(k<r){
                        swap(s[k],s[k+1]);
                        count++;
                        k++;
                    }
                }
            }
            l++,r--;
        }
        cout<<s;
        return count;
    }
};