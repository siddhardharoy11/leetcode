class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> res;
        for(int i=0;i<items1.size();i++){
            res[items1[i][0]] = items1[i][1];
        }
        for(int i=0;i<items2.size();i++)
        {   
            res[items2[i][0]]+=items2[i][1];
        }
        vector<vector<int>> ans;
        for(auto c:res){
            ans.push_back({c.first,c.second});
        }
        return ans;
    }
};
