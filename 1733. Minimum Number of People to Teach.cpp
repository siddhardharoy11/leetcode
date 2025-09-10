class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> ul(m+1);
        for(int i=0;i<m;++i)
            for(int lang:languages[i])
                ul[i+1].insert(lang);
        vector<pair<int,int>> no;
        for(auto& f:friendships){
            int u=f[0], v=f[1];
            bool shared = false;
            for(int lang:ul[u])
            if(ul[v].count(lang)){
                shared=true;
                break;
            }
            if(!shared)
            no.emplace_back(u,v);
        }
        int result=m;
        for(int lang=1;lang<=n;++lang){
            unordered_set<int> to;
            for(auto& pair: no){
                int u = pair.first, v=pair.second;
                if(ul[u].count(lang)==0) to.insert(u);
                if(ul[v].count(lang)==0) to.insert(v);
            }
            result = min(result, (int)to.size());
        }
        return result;

        }
    
};
