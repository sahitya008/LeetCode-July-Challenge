class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        if(n==1) return 1;
        int i=1,j=ratings.size()-2;
        while(i<ratings.size()){
            if(ratings[i]>ratings[i-1]){
                 left[i]=left[i-1]+1;
            }
            i++;
        }
        while(j>=0){
            if(ratings[j]>ratings[j+1])
               right[j]= right[j+1]+1;
            j--;
        }
         i=0,j=0;
        int sum=0;
        vector<int> temp;
        cout<<"aaya";
        //cout<<left[i]<<endl;
        //cout<<right[i];
        int var =0;//  max(left[0],right[0]);
        //    cout<<var;
        while(i<n){
            var=max(left[i],right[i]);
            //cout<<temp[i];
            sum+=var;
            i++;
        }
        return sum;
        
    }
};