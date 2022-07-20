class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==1){
        ans.push_back({1});
        return ans;
        }
        if(numRows==2){
        ans.push_back({1});
        ans.push_back({1,1});
        return ans;
        }
        //rememebr to make these intialisations again
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i=3;i<=numRows;i++){
            vector<int> res={1};
            for(int j=0;j<ans.back().size()-1;j++){
               int k=(ans.back()[j]+ans.back()[j+1]);
                 res.push_back(k); 
            }
            res.push_back(1);
            ans.push_back(res);
        }
     return ans;
        
    }
};