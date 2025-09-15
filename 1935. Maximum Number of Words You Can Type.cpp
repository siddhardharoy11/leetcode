// not optimised
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        string word="";
        vector<string> words;
        unordered_map<char,int> x;
        for(int i=0;i<text.length();i++)
        {
            if(text[i]==' ')
            {
                words.push_back(word);
                word="";
            }
            else{
                word+=text[i];
            }
        }
        words.push_back(word);
        int count=0;
        for(char c: brokenLetters){
            x[c]+=1;
        }
        for(string word:words){
            bool t=false;
            for(char c:word){
                if(x[c]>0){
                    t=true;
                }
            }
            if(t==false){
                count++;
            }
        }
        return count;
    }
};

//optimised
#include <unordered_set>

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenSet(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool canType = true;

        for (char c : text) {
            if (c == ' ') {
                if (canType) count++;
                canType = true;  
            } else {
                if (brokenSet.count(c)) {
                    canType = false;
                }
            }
        }

        if (canType) count++;

        return count;
    }
};
