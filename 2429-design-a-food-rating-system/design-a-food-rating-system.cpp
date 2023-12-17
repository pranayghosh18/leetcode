class FoodRatings {
public:
    unordered_map<string, map<int, set<string>>> cuisineToRatingTable;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        //cuisinToRatingTable.clear();
        for(int i=0; i<cuisines.size(); i++){
            cuisineToRatingTable[cuisines[i]][ratings[i]].insert(foods[i]);
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        // update the value
        cuisineToRatingTable[cuisine][oldRating].erase(food);
        if(cuisineToRatingTable[cuisine][oldRating].size()==0) cuisineToRatingTable[cuisine].erase(oldRating);
        cuisineToRatingTable[cuisine][newRating].insert(food);
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return *(cuisineToRatingTable[cuisine].rbegin()->second.begin());
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */