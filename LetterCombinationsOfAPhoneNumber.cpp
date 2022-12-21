class Solution {
// O(4^n) time, idk space
public:
    unordered_map<char, vector<string>> mapping = {
        {'2',{"a", "b", "c"}},
        {'3',{"d", "e", "f"}},
        {'4',{"g", "h", "i"}},
        {'5',{"j", "k", "l"}},
        {'6',{"m", "n", "o"}},
        {'7',{"p", "q", "r", "s"}},
        {'8',{"t", "u", "v"}},
        {'9',{"w", "x", "y", "z"}},
    };
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {return {};}
        return helper(digits, "");
    }

    vector<string> helper (string digits, string curr) {

        if (digits.size() == 0) {
            vector<string> res = {curr};
            return res;
        }

        char first = digits[0];
        digits.erase(0,1);

        vector<string> res;

        for (string ch: mapping[first] ) {
            string temp = curr + ch;

            for (string ans: helper(digits, temp)) {
                res.push_back(ans);
            }
        }

        digits = first + digits;

        return res;

    }
};
