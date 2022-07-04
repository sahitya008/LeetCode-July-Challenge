class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        //i was pushing h-1 and w-1 but here we need the lastyline too so we have yto push h and w as well
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxH=0,maxV=0;
        if(horizontalCuts.size()>1)
        for(int i=1;i<horizontalCuts.size();i++){
                  maxH=max(maxH,horizontalCuts[i]-horizontalCuts[i-1]);
            
        }
        else maxH=horizontalCuts[0];
        if(verticalCuts.size()>1)
         for(int j=1;j<verticalCuts.size();j++){
             maxV=max(maxV,verticalCuts[j]-verticalCuts[j-1]);
        }
        else maxV=verticalCuts[0];
        return (long)maxV*maxH %1000000007;
    }
};