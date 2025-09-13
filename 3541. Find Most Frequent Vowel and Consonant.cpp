class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowels;
        unordered_map<char,int> consonants;
        int ans;
        for(char c:s){
            if(isvowel(c))
            {
                vowels[c]++;
            }
            else{
                consonants[c]++;
            }
        }
            int maxv=0, maxc=0;
            for(const auto& c:vowels)
            {
                if(c.second>maxv)
                maxv = c.second;
            }
            for(const auto& c:consonants)
            {
                if(c.second>maxc)
                maxc = c.second;
            }
        ans = maxc+maxv;
        return ans;
    }
private:
    bool isvowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
        else
        return false;
    }
};
