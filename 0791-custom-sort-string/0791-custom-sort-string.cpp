class Solution {
public:
    static string ord;

    static bool cmp(char a, char b){
        return ord.find(a) < ord.find(b);
    }

    string customSortString(string order, string s) {
        ord = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

string Solution::ord = "";
