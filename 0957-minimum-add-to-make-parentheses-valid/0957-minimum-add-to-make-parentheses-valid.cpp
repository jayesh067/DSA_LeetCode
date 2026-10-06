class Solution {
public:
    int minAddToMakeValid(string s) {
        int appear =0;
        int open_needed = 0;
        for(auto ch : s){
            if(ch == '('){
                appear++;
            }
            else { 
                if (appear > 0) {
                    appear--; 
                } else {
                    open_needed++;
                }
            }
        }
        return appear+open_needed;
    }
};