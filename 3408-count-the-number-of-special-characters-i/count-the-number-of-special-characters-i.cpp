class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<bool, bool>> chars(26, {false, false});

        for(char ch : word) {
            if('a' <= ch && 'z' >= ch) {
                chars[ch - 'a'].first = true;
            }
            
            if('A' <= ch && 'Z' >= ch) {
                chars[ch - 'A'].second = true;
            }
        }

        int count = 0;
        for(auto pair : chars) {
            if(pair.first && pair.second) count++;
        }

        return count;
    }
};