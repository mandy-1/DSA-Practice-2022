class Solution {
public:

    int m =1e9 +7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
		
        int max_h=horizontalCuts[0], max_w=verticalCuts[0], i;
        
        for(i=1; i<horizontalCuts.size(); ++i)
            max_h = max(max_h, horizontalCuts[i]-horizontalCuts[i-1]);
        max_h = max(max_h, h-horizontalCuts[i-1]);
        
        for(i=1; i<verticalCuts.size(); ++i){
            max_w = max(max_w, verticalCuts[i]-verticalCuts[i-1]);
        }
        max_w = max(max_w, w-verticalCuts[i-1]);
     
        return ((long long)max_h*max_w)%m;
    }    
};