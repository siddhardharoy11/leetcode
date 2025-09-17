class FoodRatings {
private:
    unordered_map<string, pair<string, int>> foodInfo;
    map<string, set<pair<int, string>>> cuisineMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            string food=foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            foodInfo[food]={cuisine, rating};
            cuisineMap[cuisine].insert({-rating,food});
        }
    }
    
    void changeRating(string food, int newRating) {
auto & [cuisine,oldrating]= foodInfo[food];
    cuisineMap[cuisine].erase({-oldrating,food});
    cuisineMap[cuisine].insert({-newRating,food});
    
    foodInfo[food].second = newRating;}
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
