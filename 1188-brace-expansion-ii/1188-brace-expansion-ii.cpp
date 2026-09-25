class Solution {
public:

    // Handles UNION: a,b,c
    set<string> parseExpression(string &s, int &i) {

        set<string> result = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {

            i++; // skip ','

            set<string> next = parseTerm(s, i);

            // UNION
            result.insert(next.begin(), next.end());
        }

        return result;
    }


    // Handles CONCATENATION: abc, {a,b}{c,d}
    set<string> parseTerm(string &s, int &i) {

        // Start with empty string
        set<string> result;
        result.insert("");

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> current = parseFactor(s, i);

            set<string> temp;

            // Concatenate every possibility
            for (string a : result) {

                for (string b : current) {

                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }


    // Handles:
    // 1. normal character
    // 2. {...}
    set<string> parseFactor(string &s, int &i) {

        // { ... }
        if (s[i] == '{') {

            i++; // skip '{'

            set<string> result = parseExpression(s, i);

            i++; // skip '}'

            return result;
        }

        // Normal character
        set<string> result;

        result.insert(string(1, s[i]));

        i++;

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parseExpression(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};