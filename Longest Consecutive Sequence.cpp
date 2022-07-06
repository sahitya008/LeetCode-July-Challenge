class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int> s1;
      int count=0;
        for(auto num: nums){
            s1.insert(num);
        }
      /*  cout<<"here";
       for(auto s:s1){
           cout<<s<<endl;
       }*/
        
        for(int num: s1){
            //if element before doesnt exist,
            if(!s1.count(num-1)){
                int currNum=num;
                int currstreak=1;
                while(s1.count(currNum+1)){
                    //keep incrementing the number to get consecutive count
                    currNum+=1;
                    currstreak+=1;
                }
                count=max(count,currstreak);
            }
        }
       return count;
    }
};
/*class Solution {
public:
   int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue;
        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    }
    return r;
}
};*/