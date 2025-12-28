class Solution {
public:
void check(string num1, string num2,int p1,int p2,int carry,string& ans){
    if(p1<0 && p2<0){
        if(carry!=0){
            ans.push_back(carry+'0');
        }
        return;
    }

    int a=(p1>=0?num1[p1]:'0')-'0';
    int b=(p2>=0?num2[p2]:'0')-'0';
    int c=carry+a+b;
    int digit=c%10;
     carry=c/10;
    ans.push_back(digit+'0');


    check(num1,num2,p1-1,p2-1,carry,ans);

}


    string addStrings(string num1, string num2) {
        string ans="";
        int p1=num1.length()-1;
        int p2=num2.length()-1;
        int carry=0;
        check(num1,num2,p1,p2,carry,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};