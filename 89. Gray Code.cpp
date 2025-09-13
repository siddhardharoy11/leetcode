class Solution {
public:
    vector<int> grayCode(int n) {
        int size = pow(2,n);
        vector<int> result;
        for(int i=0;i<size;i++){
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
