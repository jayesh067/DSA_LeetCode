class Solution {
public:
    int maxDepth(string s) {
        int max_appearance = 0;
        int appearance = 0;

        for(auto ch : s){
            if(ch == '('){
                appearance++;
                max_appearance = max(max_appearance,appearance);
            }
            else if(ch == ')'){
                appearance--;
            }
        }  
        return max_appearance;
    }
};