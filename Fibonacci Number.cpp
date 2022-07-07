class Solution {
public:
  
    //Method 1 Recursion
    /* int ans=0;
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        ans=fib(n-1)+fib(n-2);
        return ans;
    }*/
    
    //method 2 iterative
    int fib(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        int a=0,b=1,count=2,sum=0;
        for(int i=2;i<=n;i++){
            sum=a+b;
            a=b;
            b=sum;
        }
        return sum;
    }
};