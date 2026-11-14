class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while(i < n && s[i] == ' '){
            i++;
        }
        int flag=1;
        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] =='-') flag=-1;
            else flag=1;
            i++;
        }
        long long ans=0;
        while(i<n && isdigit(s[i])){
            int digit = s[i]-'0';
            if(ans > (INT_MAX-digit)/10){
                if(flag==1) return INT_MAX;
                else return INT_MIN;
            }
            ans = ans*10+digit;
            i++;
        }

        return ans*flag;
    }
};