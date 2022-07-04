class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int currDiff=nums[1]-nums[0];
         int count=currDiff==0?1:2;
        if(nums.size()==2) 
            if(currDiff==0)
            return 1;
            else return 2;
        int diff=0;
        for(int i=2;i<nums.size();i++){
            diff=nums[i]-nums[i-1];
            if(currDiff>=0 && diff<0 || currDiff<=0 && diff>0){     //check the equalities here
                count++;
                currDiff=diff;     
        }
        }
        return count;
    }
};