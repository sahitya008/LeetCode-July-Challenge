class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mp;
        int i=0,count=0;
        for(auto x:s)
            mp[x].push_back(i++);
        for(int i=0;i<words.size();i++){
            string curr=words[i];
            int latest=-1;
            for(int j=0;j<curr.size();j++){
                //upper bound will giove next greatest vlaue after the latest value
                auto it=upper_bound(mp[curr[j]].begin(),mp[curr[j]].end(),latest);
                if(it==mp[curr[j]].end()) //char not found
                     break;
                latest=*it; //settying latest value
                if(j==curr.size()-1) count++;
                
            }
        }
        return count;
    }
};