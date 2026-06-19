class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();

        int wordCount = words.size();

        if(wordCount==0) return ans;

        int wordLen = words[0].size();

        unordered_map<string,int> target;

        for(auto &w:words)
            target[w]++;

        for(int offset=0;offset<wordLen;offset++){

            int left = offset;
            int count = 0;

            unordered_map<string,int> window;

            for(int right=offset;
                right+wordLen<=n;
                right+=wordLen){

                string word=s.substr(right,wordLen);

                if(target.count(word)){

                    window[word]++;
                    count++;

                    while(window[word] > target[word]){

                        string leftWord =
                            s.substr(left,wordLen);

                        window[leftWord]--;

                        left += wordLen;
                        count--;
                    }

                    if(count==wordCount){

                        ans.push_back(left);

                        string leftWord =
                            s.substr(left,wordLen);

                        window[leftWord]--;

                        left += wordLen;
                        count--;
                    }
                }
                else{

                    window.clear();

                    count=0;

                    left=right+wordLen;
                }
            }
        }

        return ans;
    }
};