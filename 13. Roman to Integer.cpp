class Solution {
public:
int romanToInt(const string& s) {
        unordered_map<char, int> mapp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int prev = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            int c = mapp[s[i]];
            
            if (current < prev)
                total -= c;  
            else
                total += c;  
            
            prev = c;
        }
        
        return total;
    }
};
