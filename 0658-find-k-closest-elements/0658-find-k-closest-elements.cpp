bool checkans(const pair<int,int> &a,const pair<int,int> &b){
    
    if(a.second==b.second){
        return a.first<b.first;
    }
    else {return a.second<b.second;}}
class Solution {

public:


    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> ans;
        for(int i=0;i<arr.size();i++){
            int dif=abs(arr[i]-x);
            ans.push_back({arr[i],dif});
            }

            sort(ans.begin(),ans.end(),checkans);
            vector<int> closer;
            for(int i=0;i<k;i++){
                closer.push_back(ans[i].first);

            }
            sort(closer.begin(),closer.end());
            return closer;
    }
};