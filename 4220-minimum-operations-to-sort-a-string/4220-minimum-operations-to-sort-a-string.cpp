class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        bool sorted = true;
        //fisrt case when string s is already sorted
        for(int i=1;i<n;i++){
            if(s[i] < s[i-1]){
                sorted = false;
                break;
            }
        }
        if(sorted) return 0;

        //second case when string 
        if(n == 2) return -1;

        //3rd case
        char mn = *min_element(s.begin(),s.end());
        char mx = *max_element(s.begin(),s.end());

        if(mn == s[0] || s[n-1] == mx) return 1;
        //4th case
        for(int i=1;i<n-1;i++){
            if(s[i] == mn || s[i] == mx){
                return 2;
            }
        }
        //5th and last case 
        return 3;
    }
};