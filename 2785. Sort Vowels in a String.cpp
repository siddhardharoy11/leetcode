class Solution {
public:
    string sortVowels(string s) {
        auto isvowel = [](char c){
            c = tolower(c);
            return c =='a' || c=='e' || c=='i' || c=='o'  || c=='u'; 
        };
        vector<char> vowels;
        for(char c:s){
            if(isvowel(c))
            vowels.push_back(c);
        }
        sort(vowels.begin(),vowels.end());
        int vowelIndex=0;
        for(int i=0;i<s.size();++i){
            if(isvowel(s[i]))
            s[i]=vowels[vowelIndex++];
        }
        return s;
    }
};
