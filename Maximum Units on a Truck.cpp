class Solution {
public:
   static bool compare(vector<int> v1, vector<int> v2){
       //if(v1[i]>v2[1])
           return v1[1]>v2[1];
      //    else return v2; 
   }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);  //i renamed trhat functiona as static, dhyaan rakhna
        int taken=0,i=0;
        while(truckSize>0 &&i<boxTypes.size()){
            if(boxTypes[i][0]<truckSize){
                 taken=taken+boxTypes[i][0]*boxTypes[i][1];
                 truckSize=truckSize-boxTypes[i][0];
                 cout<<taken<<endl;
            }
            else{
                int canTake=truckSize;
                truckSize-=canTake;
                taken+=boxTypes[i][1]*canTake;
                cout<<taken<<endl<<"inside else";
            }
        i++;
        }
        return taken;
    }
};