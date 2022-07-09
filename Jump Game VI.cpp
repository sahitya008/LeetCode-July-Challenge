class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
       /*belwo solution does not work for test case 
        [1,-5,-20,4,-1,3,-6,-3] and k=2
            so we need to store the index as in the queue*/
        /*priority_queue<int> pq;
        int score=0;
        for(auto num: nums){
            pq.push(num);
           if(pq.size()>k){
               score=score+pq.top();
           cout<<pq.top();
                pq.pop();}
            }
        return score;*/
       
        int sum=nums[0]; //dont to cover case where there is only one elment ion the array
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxH;
        maxH.push(make_pair(nums[0],0)); //sum, index
 //       or write above statement as maxH.push({nums[0],0});
        //rememeber to start the loop from i=1 as first elemnent has already been pushed in the queue
        for(int i=1;i<nums.size();i++){
            while(i-maxH.top().second>k){
                maxH.pop();
            }
            sum=nums[i]+maxH.top().first;
            maxH.push({sum,i});
        }
        return sum;
    }
};