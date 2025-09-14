class Solution {
private:
    string toLower(const string& word){
        string res=word;
        for(char& c: res){
            c = tolower(c);
        }
        return res;
    }
    string devowel(const string& word){
        string res = word;
        for(char& c:res){
            if(tolower(c)=='a'||tolower(c)=='i'||tolower(c)=='o'||tolower(c)=='u'||tolower(c)=='e'){
                c = '*';
            }
        }
        return res;
    }
public:
vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lowerMap;
        unordered_map<string, string> devowelMap;
        
        for (const string& word : wordlist) {
            exact.insert(word);
            
            string lowerWord = toLower(word);
            if (lowerMap.find(lowerWord) == lowerMap.end()) {
                lowerMap[lowerWord] = word;
            }
            
            string devowelWord = devowel(lowerWord);
            if (devowelMap.find(devowelWord) == devowelMap.end()) {
                devowelMap[devowelWord] = word;
            }
        }
        
        vector<string> result;
        for (const string& query : queries) {
            if (exact.find(query) != exact.end()) {
                result.push_back(query);
                continue;
            }
            
            string lowerQuery = toLower(query);
            if (lowerMap.find(lowerQuery) != lowerMap.end()) {
                result.push_back(lowerMap[lowerQuery]);
                continue;
            }
            
            string devowelQuery = devowel(lowerQuery);
            if (devowelMap.find(devowelQuery) != devowelMap.end()) {
                result.push_back(devowelMap[devowelQuery]);
                continue;
            }
            
            result.push_back("");
        }
        
        return result;
    }
};
