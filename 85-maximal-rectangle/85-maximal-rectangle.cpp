class Solution {
public:
    int f(vector<int>&hist){
        int n=hist.size();
        stack<int>temp;
        int maxio=0;
        
        for(int i=0;i<=n;i++){
            while(!temp.empty() && (i==n || hist[i]<=hist[temp.top()])){
                int hg = hist[temp.top()];
                temp.pop();
                int width=0;
                if(temp.empty()) width=i;
                else width = i-temp.top()-1;
                maxio = max(maxio,width*hg);
            }
            temp.push(i);
        }
        return maxio;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
       int m=matrix[0].size();
        int n=matrix.size();
        vector<int>hist(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    hist[j]++;
                }
                else{
                    hist[j]=0;
                }
            }
            maxi=max(maxi,f(hist));
        }
        return maxi;
    }
};