class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> map = { 
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
         };

        for (char ch : s) {
            if (map.count(ch) == 0) {
                if (stack.size() == 0 || stack.back() != ch) {
                    return false;
                }
                stack.pop_back();
            }
            else {
                stack.push_back(map[ch]);
            }
        }

        return stack.size() == 0;

        
    }
};
