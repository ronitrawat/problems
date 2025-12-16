class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> m;
       vector<vector<string>> result;
      for(int i=0;i<strs.size();i++){
        if(strs.size()==0){
            return result;
        }
        
        else{
            string a=strs[i];
          sort(a.begin(),a.end());
            m[a].push_back(strs[i]);

        }
      }
     

for (auto &p : m) {
    result.push_back(p.second);
}

return result;


    }
};