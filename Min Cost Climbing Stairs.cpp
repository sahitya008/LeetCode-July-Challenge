class Solution {
public:
    
    //METHOD 1: Recursion
/*    int solve(vector<int> &cost, int n){
      //BASE CASE
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        
        int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
        return ans;
    }*/
    //Method 2: adding memorization
     int solve2(vector<int> &cost, int n,vector<int> &dp){
      //BASE CASE
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        
         //step2: check value in dp array
         if(dp[n]!=-1)
             return dp[n];
             
         //step 3: store values in dp array    
        dp[n]=cost[n]+min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return dp[n];
    }
    
    //Method 3:TABULATION
     int solve3(vector<int> &cost, int n){
        vector<int> dp(n+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
             dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
         }
         return min(dp[n-1],dp[n-2]);
     }
    
     
     int solve4(vector<int> &cost, int n){
         int prev1=cost[0];
         int prev2=cost[1];
         for(int i=2;i<n;i++){
             int curr=cost[i]+min(prev1,prev2);
             prev1=prev2;
             prev2=curr;
         }
         return min(prev1,prev2);
     }
    
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       // vector<int> dp(n+1,-1);
        //below is recursive call
        //int x=min(solve(cost,n-1), solve(cost,n-2));
       
        //below is call to DP function
        //int x=min(solve2(cost,n-1,dp), solve2(cost,n-2,dp));
       
        //return solve3(cost,n);
        
        return solve4(cost,n);
         
    }
    
    
    
};