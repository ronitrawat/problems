class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int countp=0;
        int lastp=0;
        int totalp=0;

         int countm=0;
        int lastm=0;
        int totalm=0;

         int countg=0;
        int lastg=0;
        int totalg=0;

        for(int i=0;i<garbage.size();i++){
            for(auto m:garbage[i]){
                if(m=='G'){
                    countg++;
                    lastg=i;
                }
                if(m=='M'){
                    countm++;
                    lastm=i;
                }
                if(m=='P'){
                    countp++;
                    lastp=i;
                }


            }

        }


        for(int i=0;i<lastp;i++){
            totalp+=travel[i];
        }
        for(int i=0;i<lastg;i++){
            totalg+=travel[i];
        }
        for(int i=0;i<lastm;i++){
            totalm+=travel[i];
        }
         int ans=0;
         ans=totalp+totalg+totalm+countp+countm+countg;

     return ans;
    }
};